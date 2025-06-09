use rand::prelude::*;

use crate::params;

#[derive(Debug)]
pub enum FallingMode {
    NoFall,
    Center,
    ArcToLeft,
    ArcToRight,
}

#[derive(Debug)]
pub struct Berry {
    pub x: i32,
    pub y: i32,
    pub rad: i32,
    pub fallmode: FallingMode,
}

impl Berry {
    pub fn new(x: i32, y: i32, radius: i32) -> Self {
        Berry {
            x: x,
            y: y,
            rad: radius,
            fallmode: FallingMode::Center,
        }
    }

    pub fn fall(&mut self) {
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

    pub fn collision_with(&self, other: &Berry) -> bool {
        let dist: i32 = ((self.x - other.x).pow(2) + (self.y - other.y).pow(2)).isqrt();
        if dist <= (self.rad + other.rad) {
            //println!("s{:?}   o{:?}", self, other);
            return true;
        }
        return false;
    }

    pub fn collision_with_point(&self, x: i32, y:i32) -> bool {
        let dist: i32 = ((self.x - x).pow(2) + (self.y - y).pow(2)).isqrt();
        if dist <= self.rad {
            return true;
        }
        return false;
    }
}

impl Distribution<Berry> for rand::distr::StandardUniform {
    fn sample<R: Rng + ?Sized>(&self, rng: &mut R) -> Berry {
        let rand_x: i32 = rng.random_range(params::GAME_RANDOM_MIN_X..params::GAME_RANDOM_MAX_X);
        let rand_y: i32 = rng.random_range(params::GAME_RANDOM_MIN_Y..params::GAME_RANDOM_MAX_Y);
        let rand_rad: i32 = rng.random_range(params::BERRY_MIN_RAD..params::BERRY_MAX_RAD);
        Berry {
            x: rand_x,
            y: rand_y,
            rad: rand_rad,
            fallmode: FallingMode::Center,
        }
    }
}