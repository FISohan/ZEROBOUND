#ifndef ENEMY_H

#define ENEMY_H
#define SEPARATION_RADIUS 60.0f   // about 1.5-2x enemy size, in pixels
#define SEEK_WEIGHT       1.0f
#define SEPARATION_WEIGHT 1.5f

#include "raylib.h"
#include "number.h"

typedef struct 
{
   Vector2 position;
   Vector2 velocity;
   Number number;
   float chasing_speed;
} Enemy;

void chasing_player(Enemy *enemy, Vector2 playerPosition, Enemy *all, int count);
void drawEnemy(Enemy *enemy);

#endif