//! A silly experiment after dinner... (for two)  
//! This is not the final game
//! 
//! # Missing features (roadmap)
//! 
//! * [ ] Better implementation of physics/gravity
//! * [ ] Add documentation test (for cargo test)
//! * [ ] Create walls (berries contained inside a jar)
//! * [ ] Add player1, player2, scores, ...
//! * [ ] Add game menù (play, restart, quit)
//! 
//! Only for educational purpose remove some of the "use clause" and write full namespaces.
//! 
//! # Notes
//! 
//! On main function use `OpenGL__V2_1` if not working v3.2

extern crate glutin_window;
extern crate graphics;
extern crate opengl_graphics;
extern crate piston;

use piston::PressEvent;
use piston::input::*;
use rand::prelude::*;

use graphics::Transformed;
use opengl_graphics::{GlGraphics, OpenGL};
use piston::event_loop::{EventSettings, Events};
use piston::input::{RenderArgs, RenderEvent, UpdateArgs, UpdateEvent};

/// Game area
const GAME_BOARD_WIDTH: u32 = 600;
const GAME_BOARD_HEIGHT: u32 = 600;

/// Min and Max position for berries (center)
const GAME_RANDOM_MIN_X: i32 = 50;
const GAME_RANDOM_MAX_X: i32 = GAME_BOARD_WIDTH as i32 - GAME_RANDOM_MIN_X;
const GAME_RANDOM_MIN_Y: i32 = 100;
const GAME_RANDOM_MAX_Y: i32 = GAME_BOARD_HEIGHT as i32 - GAME_RANDOM_MIN_Y;

/// Man number of berries generated (=dropped) at startup
const BERRY_ON_BASKET: i32 = 30;
/// Vertical distance between generated berries
const BERRY_DIST_WHEN_DROPPING: i32 = 100;

// Min and Max berry size
const BERRY_MIN_RAD: i32 = 20;
const BERRY_MAX_RAD: i32 = 50;

#[derive(Debug)]
enum FallingMode {
    NoFall,
    Center,
    ArcToLeft,
    ArcToRight,
}

#[derive(Debug)]
pub struct Berry {
    x: i32,
    y: i32,
    rad: i32,
    fallmode: FallingMode,
}

impl Berry {
    fn new(x: i32, y: i32, radius: i32) -> Self {
        Berry {
            x: x,
            y: y,
            rad: radius,
            fallmode: FallingMode::Center,
        }
    }

    fn fall(&mut self) {
        match self.fallmode {
            FallingMode::ArcToLeft =>
            {
                self.x -= 6;
                self.y += 1;
            },
            FallingMode::ArcToRight =>
            {
                self.x += 6;
                self.y += 1;
            },
           FallingMode::Center =>
           {
                self.y += 5;
           },
            _ => (),
        }
    }

    fn collision_with(&self, other: &Berry) -> bool {
        let dist: i32 = ((self.x - other.x).pow(2) + (self.y - other.y).pow(2)).isqrt();
        if dist <= (self.rad + other.rad) {
            //println!("s{:?}   o{:?}", self, other);
            return true;
        }
        return false;
    }

    fn collision_with_point(&self, x: i32, y:i32) -> bool {
        let dist: i32 = ((self.x - x).pow(2) + (self.y - y).pow(2)).isqrt();
        if dist <= self.rad {
            return true;
        }
        return false;
 
    }
}

impl Distribution<Berry> for rand::distr::StandardUniform {
    fn sample<R: Rng + ?Sized>(&self, rng: &mut R) -> Berry {
        let rand_x: i32 = rng.random_range(GAME_RANDOM_MIN_X..GAME_RANDOM_MAX_X);
        let rand_y: i32 = rng.random_range(GAME_RANDOM_MIN_Y..GAME_RANDOM_MAX_Y);
        let rand_rad: i32 = rng.random_range(BERRY_MIN_RAD..BERRY_MAX_RAD);
        Berry {
            x: rand_x,
            y: rand_y,
            rad: rand_rad,
            fallmode: FallingMode::Center,
        }
    }
}

pub struct App {
    gl: GlGraphics,         // OpenGL drawing backend
    berries: Vec<Berry>,    // List of berries available on game area
    ground: i32,            // Vertical position of the ground
}

impl App {
    fn new(opengl: OpenGL) -> Self {
        let mut berries: Vec<Berry> = Vec::new();
        let mut rng = rand::rng();
        for nb in 0..BERRY_ON_BASKET {
            let mut b: Berry = rng.sample(rand::distr::StandardUniform);
            b.y = (-1) * BERRY_DIST_WHEN_DROPPING * (nb as i32);
            berries.push(b);
        }

        App {
            gl: GlGraphics::new(opengl),
            berries: berries,
            ground: 550,
        }
    }

    fn gravity(&mut self) {
        for b_idx in 0..self.berries.len() {

            let mut left_collision: bool = false;
            let mut right_collision: bool = false;
            let mut center_collision: bool = false;

            // check collision with others berries, below the current one
            for compare_idx in 0..self.berries.len() {

                if (b_idx != compare_idx) && (self.berries[b_idx].y <= self.berries[compare_idx].y) {
                    if self.berries[b_idx].collision_with(&self.berries[compare_idx]) {                        
                        if self.berries[b_idx].x < self.berries[compare_idx].x {
                            left_collision = true;
                            continue;
                        }
                        if self.berries[b_idx].x > self.berries[compare_idx].x {
                            right_collision = true;
                            continue;
                        }
                        if self.berries[b_idx].x == self.berries[compare_idx].x {
                            center_collision = true;
                            break;
                        }
                    }
                }
            }

            if center_collision || (left_collision && right_collision) {
                self.berries[b_idx].fallmode = FallingMode::NoFall;
            }
            else if left_collision {
                self.berries[b_idx].fallmode = FallingMode::ArcToLeft;
            }
            else if right_collision {
                self.berries[b_idx].fallmode = FallingMode::ArcToRight;
            }
            else {                
                self.berries[b_idx].fallmode = FallingMode::Center;
            }
 
            // check collision with ground
            if (self.berries[b_idx].y + self.berries[b_idx].rad) >= self.ground {
                self.berries[b_idx].fallmode = FallingMode::NoFall;
            }
                        
            self.berries[b_idx].fall();
        }
    }

    fn pick_berry (&mut self, x: i32, y:i32) {
        for b_idx in 0..self.berries.len() {
            if self.berries[b_idx].collision_with_point(x, y) {
                self.berries.remove(b_idx);
                break;
            }
        }
    }

    fn render(&mut self, args: &RenderArgs) {
        const WHITE: [f32; 4] = [1.0, 1.0, 1.0, 1.0];
        const GREEN: [f32; 4] = [0.0, 1.0, 0.0, 1.0];
        const RED: [f32; 4] = [1.0, 0.0, 0.0, 1.0];
        const BLUE: [f32; 4] = [0.2, 0.3, 0.5, 1.0];

        //let square = graphics::rectangle::square(20.0, 20.0, 40.0);

        self.gl.draw(args.viewport(), |c, gl| {
            // Clear the screen.
            graphics::clear(WHITE, gl);

            // You need to apply a transformation even if not used...
            let transform = c.transform.trans(0.0, 0.0).rot_deg(0.0);

            let floor = [0.0, self.ground as f64, GAME_BOARD_WIDTH as f64, 50.0];
            graphics::rectangle(GREEN, floor, transform, gl);

            // Get the berries
            // (make rectangles of them and then plot)
            for b in &self.berries {
                let square_berry = graphics::rectangle::square(
                    b.x as f64 - b.rad as f64, 
                    b.y as f64 - b.rad as f64, 
                    b.rad as f64 + b.rad as f64
                );
                graphics::ellipse(BLUE, square_berry, transform, gl);
            }
        });
    }

    fn update(&mut self, args: &UpdateArgs) {

    }
}

fn main() {
    // Change this to OpenGL::V2_1 if not working.
    let opengl = OpenGL::V3_2;

    // Create game window
    let mut game_window: glutin_window::GlutinWindow =
        piston::WindowSettings::new("nibble-berry-game", [GAME_BOARD_WIDTH, GAME_BOARD_HEIGHT])
            .graphics_api(opengl)
            .exit_on_esc(true)
            .resizable(false)
            .build()
            .unwrap();

    // Create a new game and run it
    let mut game_app = App::new(opengl);

    // Store mouse position
    let mut cursor = [0, 0];

    // Manage events
    let mut events = Events::new(EventSettings::new());
    while let Some(e) = events.next(&mut game_window) {

        e.mouse_cursor(|pos| {
            cursor[0] = pos[0] as i32;
            cursor[1] = pos[1] as i32;
        });
 
        if let Some(Button::Mouse(button)) = e.press_args() {
            game_app.pick_berry(cursor[0], cursor[1]);
        }

        if let Some(args) = e.render_args() {
            game_app.gravity();
            game_app.render(&args);
        }

        if let Some(args) = e.update_args() {
            game_app.update(&args);
        }
    }
}
