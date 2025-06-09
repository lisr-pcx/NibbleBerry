//! Global parameters for the game

/// Window width
pub const GAME_BOARD_WIDTH: u32 = 600;
/// Window height
pub const GAME_BOARD_HEIGHT: u32 = 600;

// Min and Max position for berries (center)

pub const GAME_RANDOM_MIN_X: i32 = 50;
pub const GAME_RANDOM_MAX_X: i32 = GAME_BOARD_WIDTH as i32 - GAME_RANDOM_MIN_X;
pub const GAME_RANDOM_MIN_Y: i32 = 100;
pub const GAME_RANDOM_MAX_Y: i32 = GAME_BOARD_HEIGHT as i32 - GAME_RANDOM_MIN_Y;

/// Man number of berries generated (=dropped) at startup
pub const BERRY_ON_BASKET: i32 = 30;
/// Vertical distance between generated berries
pub const BERRY_DIST_WHEN_DROPPING: i32 = 100;

/// Min berry size
pub const BERRY_MIN_RAD: i32 = 20;
/// Max berry size
pub const BERRY_MAX_RAD: i32 = 50;