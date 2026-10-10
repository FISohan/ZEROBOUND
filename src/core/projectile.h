#ifndef PROJECTILE_H
#define PROJECTILE_H
#define PROJECTILE_SPEED 600.0

#include "raylib.h"

typedef struct{
    Vector2 position;
    Vector2 velocity;
} Projectile;

void init_projectile(Projectile *projectile, Vector2 initPos);
void shoot_projectile(Projectile *projectile);
void render_projectile(Projectile *projectile);

#endif