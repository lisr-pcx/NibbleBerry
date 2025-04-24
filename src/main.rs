// Just play around... this is not the final game

// Set toolchain:
//      $ cargo add bevy
//      $ rustup update
//      $ rustup install 1.86.0
//      $ rustup default 1.86.0

// System libraries missing (on my laptop)
//      $ sudo dnf makecache --refresh
//      $ sudo dnf install gcc-c++ libX11-devel alsa-lib-devel systemd-devel

extern crate glutin_window;
extern crate graphics;
extern crate opengl_graphics;
extern crate piston;

use rand::prelude::*;

//use glutin_window::GlutinWindow as Window;
use graphics::Transformed;
use opengl_graphics::{GlGraphics, OpenGL};
use piston::event_loop::{EventSettings, Events};
use piston::input::{RenderArgs, RenderEvent, UpdateArgs, UpdateEvent};
//use piston::window::WindowSettings;

const GAME_BOARD_WIDTH: u32 = 600;
const GAME_BOARD_HEIGHT: u32 = 600;

const GAME_RANDOM_MIN_X: i32 = 50;
const GAME_RANDOM_MAX_X: i32 = GAME_BOARD_WIDTH as i32 - GAME_RANDOM_MIN_X;
const GAME_RANDOM_MIN_Y: i32 = 100;
const GAME_RANDOM_MAX_Y: i32 = GAME_BOARD_HEIGHT as i32 - GAME_RANDOM_MIN_Y;

const BERRY_ON_BASKET: i32 = 30;
const BERRY_DIST_WHEN_DROPPING: i32 = 100;
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
                self.x -= 5;
                self.y += 1;
            },
            FallingMode::ArcToRight =>
            {
                self.x += 5;
                self.y += 1;
            },
           FallingMode::Center =>
           {
                self.y += 5;
           },
            _ =>
                println!("no fall"),
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
    gl: GlGraphics, // OpenGL drawing backend
    berries: Vec<Berry>,
    ground: i32,
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

    fn render(&mut self, args: &RenderArgs) {
        const WHITE: [f32; 4] = [1.0, 1.0, 1.0, 1.0];
        const GREEN: [f32; 4] = [0.0, 1.0, 0.0, 1.0];
        const RED: [f32; 4] = [1.0, 0.0, 0.0, 1.0];

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
                graphics::ellipse(RED, square_berry, transform, gl);
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

    // Create a new game and run it.
    let mut game_app = App::new(opengl);

    let mut events = Events::new(EventSettings::new());
    while let Some(e) = events.next(&mut game_window) {
        if let Some(args) = e.render_args() {
            game_app.gravity();
            game_app.render(&args);
        }

        if let Some(args) = e.update_args() {
            game_app.update(&args);
        }
    }
}
