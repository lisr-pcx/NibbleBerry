# NibbleBerry

A silly experiment after dinner... (for two)

Live demo currently not available.

## Toolchain

rustc 1.77.1

This simple game uses Bevy Engine, further info ([here](https://bevyengine.org/)).

## Design

Turn-based game.  
A pair number of berries is available inside a jar.
The goal is to pick (=remove) berries to earn points.  
Each player get points based on the number of berries moved after the picking.  
The difference in size between the berry picked by player will cut the points earned on that turn.

## Physics model of berries

The *gravity* is applied without acceleration.

Berries when are touching together (or the jar) are *kind of sticky*.

For each berry:
- check berris below
- calculate distance between centers, and when it's less than the sum of radius then it's a contact point. Store it.
- based on the number of contact points related to the center of the berry (x-axis):
  - no contact points: free fall
  - contact points on the left and on the right: do not fall
  - contact points only on one side: fall also sliding to the other side

## Live demo

Currently not available [here](https://lisr-pcx.github.io/NibbleBerry/index.html)

Instructions: just click to pickup desired berry.
