#include "projectile.h"
#include "raylib.h"
#include "raymath.h"

void init_projectile(Projectile *projectile, Vector2 initPos){
    projectile->position = initPos;
};

void shoot_projectile(Projectile *projectile){
    Vector2 normalised_direction = Vector2Normalize(projectile->velocity);
    float dt = GetFrameTime();
    projectile->position.x += normalised_direction.x * dt * PROJECTILE_SPEED;
    projectile->position.y += normalised_direction.y * dt * PROJECTILE_SPEED;
};

void render_projectile(Projectile *projectile){
    DrawCircle(projectile->position.x,projectile->position.y,PROJECTILE_REDIUS,GREEN);
};
