#include "player.h"
#include "raylib.h"
#include "raymath.h"

#define PLAYER_SPEED 400.0
#define PLAYER_RADIUS 10.0

void player_init(Player *player)
{
    player->position = (Vector2){30.0, 20.0};
    player->aim_position = (Vector2){20.0,50.0};
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

    if (Vector2Length(direction) > 0.0)
    {
        direction = Vector2Normalize(direction);
    }

    player->position.x += direction.x * PLAYER_SPEED * dt;
    player->position.y += direction.y * PLAYER_SPEED * dt;

    player->position.x = Clamp(player->position.x, PLAYER_RADIUS, GetScreenWidth() - PLAYER_RADIUS);
    player->position.y = Clamp(player->position.y, PLAYER_RADIUS, GetScreenHeight() - PLAYER_RADIUS);
}

static void update_aim(Player *player){
    Vector2 mouse_position = GetMousePosition();
    TraceLog(LOG_INFO,"[%lf %lf]",mouse_position.x,mouse_position.y);
    player->aim_position = mouse_position;
}

static void render_aim(Player *player){
    DrawCircle(player->aim_position.x,player->aim_position.y,5.0,RED);
}

void update_player(Player *player)
{
    player_movement(player);
    update_aim(player);
}

void rendar_player(Player *player)
{
    DrawCircle(player->position.x, player->position.y, PLAYER_RADIUS, WHITE);
    render_aim(player);
};
