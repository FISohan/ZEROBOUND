#ifndef PROJECTILE_H
#define PROJECTILE_H
#define PROJECTILE_SPEED 700.0

#include "raylib.h"

typedef struct{
    Vector2 position;
} Projectile;

void init_projectile(Projectile *projectile, Vector2 initPos);
void shoot_projectile(Projectile *projectile, Vector2 direction);
void render_projectile(Projectile *projectile);

#endif