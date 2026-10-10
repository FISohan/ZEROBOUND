#include "projectile.h"
#include "raylib.h"
#include "raymath.h"

void init_projectile(Projectile *projectile, Vector2 init_pos){
    projectile->position = init_pos;
};

void shoot_projectile(Projectile *projectile,Vector2 direction){
    Vector2 normalised_direction = Vector2Normalize(direction);
    float dt = GetFrameTime();
    projectile->position.x += normalised_direction.x * dt * PROJECTILE_SPEED;
    projectile->position.y += normalised_direction.y * dt * PROJECTILE_SPEED;
};

void render_projectile(Projectile *projectile){
    DrawCircle(projectile->position.x,projectile->position.y,5.0,GREEN);
};
