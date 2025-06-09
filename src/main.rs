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

use opengl_graphics::{GlGraphics, OpenGL};
use piston::PressEvent;
use piston::input::*;
use piston::event_loop::{EventSettings, Events};

pub mod params;
pub mod game;
pub mod berry;

fn main() {
    // Change this to OpenGL::V2_1 if not working.
    let opengl = OpenGL::V3_2;

    // Create game window
    let mut game_window: glutin_window::GlutinWindow =
        piston::WindowSettings::new("nibble-berry-game", [params::GAME_BOARD_WIDTH, params::GAME_BOARD_HEIGHT])
            .graphics_api(opengl)
            .exit_on_esc(true)
            .resizable(false)
            .build()
            .unwrap();

    // Create a new game and run it
    let mut game_app = game::App::new(opengl);

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