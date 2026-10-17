#include "enemy.h"
#include "raylib.h"

void chasing_player(Enemy *enemy, Vector2 playerPosition, Enemy *all, int count)
{
    float dt = GetFrameTime();

    // 1. Seek: unit vector toward the player
    Vector2 seek = Vector2Normalize(Vector2Subtract(playerPosition, enemy->position));

    // 2. Separation: sum of pushes away from close neighbors
    Vector2 sep = {0, 0};
    for (int i = 0; i < count; i++)
    {
        Enemy *other = &all[i];
        if (other == enemy) continue;                  // skip yourself

        Vector2 away = Vector2Subtract(enemy->position, other->position);
        float dist = Vector2Length(away);

        if (dist > 0.0f && dist < SEPARATION_RADIUS)
        {
            float strength = (SEPARATION_RADIUS - dist) / SEPARATION_RADIUS; // 0 far, 1 touching
            sep = Vector2Add(sep, Vector2Scale(Vector2Normalize(away), strength));
        }
    }

    // 3. Blend the two desires
    Vector2 dir = Vector2Add(Vector2Scale(seek, SEEK_WEIGHT),
                             Vector2Scale(sep,  SEPARATION_WEIGHT));
    if (Vector2Length(dir) > 0.0f) dir = Vector2Normalize(dir);

    // 4. Move at constant speed along the blended direction
    enemy->velocity = Vector2Scale(dir, enemy->chasing_speed * dt);
    enemy->position = Vector2Add(enemy->position, enemy->velocity);
}   

void drawEnemy(Enemy *enemy)
{
    DrawCircle(enemy->position.x, enemy->position.y, 10, YELLOW);
}
