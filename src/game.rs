use opengl_graphics::{GlGraphics, OpenGL};
use piston::input::{RenderArgs, RenderEvent, UpdateArgs, UpdateEvent};
use graphics::Transformed;
use rand::prelude::*;

use crate::params;
use crate::berry;

pub struct App {
    gl: GlGraphics,                 // OpenGL drawing backend
    berries: Vec<berry::Berry>,     // List of berries available on game area
    ground: i32,                    // Vertical position of the ground
}

impl App {
    pub fn new(opengl: OpenGL) -> Self {
        let mut berries: Vec<berry::Berry> = Vec::new();
        let mut rng = rand::rng();
        for nb in 0..params::BERRY_ON_BASKET {
            let mut b: berry::Berry = rng.sample(rand::distr::StandardUniform);
            b.y = (-1) * params::BERRY_DIST_WHEN_DROPPING * (nb as i32);
            berries.push(b);
        }

        App {
            gl: GlGraphics::new(opengl),
            berries: berries,
            ground: 550,
        }
    }

    pub fn gravity(&mut self) {
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
                self.berries[b_idx].fallmode = berry::FallingMode::NoFall;
            }
            else if left_collision {
                self.berries[b_idx].fallmode = berry::FallingMode::ArcToLeft;
            }
            else if right_collision {
                self.berries[b_idx].fallmode = berry::FallingMode::ArcToRight;
            }
            else {                
                self.berries[b_idx].fallmode = berry::FallingMode::Center;
            }
 
            // check collision with ground
            if (self.berries[b_idx].y + self.berries[b_idx].rad) >= self.ground {
                self.berries[b_idx].fallmode = berry::FallingMode::NoFall;
            }
                        
            self.berries[b_idx].fall();
        }
    }

    pub fn pick_berry (&mut self, x: i32, y:i32) {
        for b_idx in 0..self.berries.len() {
            if self.berries[b_idx].collision_with_point(x, y) {
                self.berries.remove(b_idx);
                break;
            }
        }
    }

    pub fn render(&mut self, args: &RenderArgs) {
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

            let floor = [0.0, self.ground as f64, params::GAME_BOARD_WIDTH as f64, 50.0];
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

    pub fn update(&mut self, args: &UpdateArgs) {

    }
}
