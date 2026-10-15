#include "enemy.h"
#include "raylib.h"

void chasing_player(Enemy *enemy, Vector2 playerPosition){
    Vector2 dir = Vector2Subtract(playerPosition,enemy->position);
    Vector2 normalisedDir = Vector2Normalize(dir);
    float dt = GetFrameTime();
    enemy->position.x += normalisedDir.x * enemy->chasing_speed * dt; 
    enemy->position.y += normalisedDir.y * enemy->chasing_speed * dt; 
}

void drawEnemy(Enemy *enemy){
    DrawCircle(enemy->position.x,enemy->position.y,10,YELLOW);
}
