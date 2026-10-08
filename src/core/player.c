#include "player.h"
#include "raylib.h"
#include "raymath.h"

#define PLAYER_SPEED 400.0
#define PLAYER_RADIUS 10.0

void player_init(Player *player)
{
    player->position = (Vector2){30.0, 20.0};
}

static int is_on_screen(Player *player)
{
    Vector2 pos = player->position;

    return !(pos.x - PLAYER_RADIUS <= 0 ||
             pos.x + PLAYER_RADIUS >= GetScreenWidth() ||
             pos.y - PLAYER_RADIUS <= 0 ||
             pos.y + PLAYER_RADIUS >= GetScreenHeight());
}

static void player_movement(Player *player)
{
    float dt = GetFrameTime();
    Vector2 direction = {0.0};

    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;

    if(Vector2Length(direction) > 0.0){
        direction = Vector2Normalize(direction);
    }

    player->position.x += direction.x * PLAYER_SPEED * dt;
    player->position.y += direction.y * PLAYER_SPEED * dt;

    player->position.x = Clamp(player->position.x, PLAYER_RADIUS, GetScreenWidth() - PLAYER_RADIUS);
    player->position.y = Clamp(player->position.y, PLAYER_RADIUS, GetScreenHeight() - PLAYER_RADIUS);
}


void update_player(Player *player){
    player_movement(player);
}

void rendar_player(Player *player)
{
    DrawCircle(player->position.x, player->position.y, PLAYER_RADIUS, WHITE);
};
