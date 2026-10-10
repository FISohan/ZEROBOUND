#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include "gun.h"

#define PLAYER_SPEED 500.0
#define PLAYER_RADIUS 20.0

void player_init(Player *player)
{
    player->position = (Vector2){30.0, 20.0};
    player->aim_position = (Vector2){20.0, 50.0};
    player->event = NONE;
    Projectile b;

    Gun gun1 = {.type = PLUS_ONE, .bullet = b};
    player->guns[0] = gun1;
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

static void update_aim(Player *player)
{
    Vector2 mouse_position = GetMousePosition();
    player->aim_position = mouse_position;
}

static void render_aim(Player *player)
{
    DrawCircle(player->aim_position.x, player->aim_position.y, 5.0, RED);
}

static void weapon_trigger(Player *player)
{
    if (IsKeyDown(KEY_SPACE))
    {
        fire_gun(player);
    }
    if (IsKeyUp(KEY_SPACE))
    {
        player->event = NONE;
    }
}

void update_event(Player *player, PlayerEvent event)
{
    player->event = event;
}

void fire_gun(Player *player)
{
    // Later active_gun will set by player
    player->active_gun = player->guns[0];

    init_projectile(&player->active_gun.bullet, player->position);
    Vector2 velocityDirecton = Vector2Subtract(player->aim_position, player->position);
    player->active_gun.bullet.velocity = velocityDirecton;
    player->active_gun.bullet.active = true;
    player->event = PROJECTILE_FIRED;
}

void update_player(Player *player)
{
    player_movement(player);
    update_aim(player);
    weapon_trigger(player);
}

void render_player(Player *player)
{
    DrawCircle(player->position.x, player->position.y, PLAYER_RADIUS, WHITE);
    render_aim(player);
};
