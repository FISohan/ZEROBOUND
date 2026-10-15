#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"
#include "number.h"

typedef struct 
{
   Vector2 position;
   Number number;
   float chasing_speed;
} Enemy;

void chasing_player(Enemy *enemy,Vector2 playerPosition);
void drawEnemy(Enemy *enemy);

#endif