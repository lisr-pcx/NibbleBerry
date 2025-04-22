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

use num_integer::Roots;

use glutin_window::GlutinWindow as Window;
use graphics::Transformed;
use opengl_graphics::{GlGraphics, OpenGL};
use piston::event_loop::{EventSettings, Events};
use piston::input::{RenderArgs, RenderEvent, UpdateArgs, UpdateEvent};
use piston::window::WindowSettings;

const GAME_BOARD_WIDTH: u32 = 600;
const GAME_BOARD_HEIGHT: u32 = 600;

#[derive(Debug)]
pub struct Berry {
    x: i32,
    y: i32,
    rad: i32,
}

impl Berry {
    fn new(x: i32, y: i32, radius: i32) -> Self {
        Berry {
            x: x,
            y: y,
            rad: radius,
        }
    }

    fn collision_with(&self, other: &Berry) -> bool {
        let dist: i32 = ((self.x - other.x).pow(2) + (self.y - other.y).pow(2)).isqrt();
        if dist <= (self.rad + other.rad) {
            println!("s{:?}   o{:?}", self, other);
            return true;
        }
        return false;
    }
}

pub struct App {
    gl: GlGraphics, // OpenGL drawing backend
    berries: Vec<Berry>,
    ground: i32,
}

impl App {
    fn new(opengl: OpenGL) -> Self {
        let b1 = Berry::new(50, 50, 20);
        let b2 = Berry::new(350, 250, 60);
        let b3 = Berry::new(500, 100, 40);
        let b4 = Berry::new(400, 20, 40);
        let b5 = Berry::new(280, 80, 30);
        let mut bbb: Vec<Berry> = Vec::new();
        bbb.push(b1);
        bbb.push(b2);
        bbb.push(b3);
        bbb.push(b4);
        bbb.push(b5);

        App {
            gl: GlGraphics::new(opengl),
            berries: bbb,
            ground: 550,
        }
    }

    fn gravity(&mut self) {
        for b_idx in 0..self.berries.len() {

            let mut free_fall : bool = true;

            for compare_idx in 0..self.berries.len() {
                if b_idx != compare_idx {
                    if self.berries[b_idx].collision_with(&self.berries[compare_idx]) {
                        free_fall = false;
                        continue;
                    }
                }
            }

            if (self.berries[b_idx].y + self.berries[b_idx].rad) >= self.ground {
                free_fall = false;
            }
            
            if free_fall == true {
                self.berries[b_idx].y += 5;
            }
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
