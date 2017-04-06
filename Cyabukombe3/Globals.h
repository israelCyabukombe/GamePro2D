#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include<list>

#define BLACK al_map_rgb(0,0,0)
#define LIGHTBLUE   al_map_rgb(204,255,255)
#define RED     al_map_rgb(255,0,0)
#define GREEN   al_map_rgb(0,255,0)
#define BLUE    al_map_rgb(0,0,255)
#define YELLOW  al_map_rgb(255,255,0)
#define MAGENTA al_map_rgb(255,0,255)
#define WHITE   al_map_rgb(255,255,255)
#define BULLET_COLOR al_map_rgb(102,0,51) 
#define MAROON al_map_rgb(128,0,0)
#define GRAY al_map_rgb(96,96,96)
#define NAVY al_map_rgb(0,0,128)
#define CADETBLUE al_map_rgb(0,153,153)

enum State { INIT, TITLE, PLAYING, OVER, EXIT };
enum Id { PLAYER, BULLET, ENEMY, BORDER, MISC };
enum Keys { ESCAPE, UP, DOWN, LEFT, RIGHT, SPACE };

const int WIDTH = 800;
const int HEIGHT = 400;
const int FPS = 60;
const int COMET_CHANCE = 100;

const int SHIP_SPEED = 6;
const int SHIP_BODY_WIDTH = 20;
const int SHIP_BODY_LENGTH = 40;
const int SHIP_WING_SPAN = 17;
const int SHIP_WING_LENGTH = 24;
const int SHIP_BOUND_X = 12;
const int SHIP_BOUND_Y = 17;
const int GUN_PLACEMENT = 9;
const int GUN_LENGTH = 10;

const int BULLET_SPEED = 10;
const int BULLET_RADIUS = 2;
const int BULLET_BOUND_X = 1;
const int BULLET_BOUND_Y = 1;
const int BULLET_PLACEMENT = 17;
const int NUM_BULLETS = 5;

const int COMET_SPEED = 5;
const int COMET_RADIUS1 = 30;
const int COMET_RADIUS2 = 17;
const int COMET_BOUND_X = 30;
const int COMET_BOUND_Y = 30;

const int EXPLOSION_RADIUS = 50;