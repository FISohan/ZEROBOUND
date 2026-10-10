
#include "game.h"
#include "player.h"
#include "raymath.h"

void create_projectile_pool(Game *game)
{
    for (int i = 0; i < POOl_SIZE - 2; i++)
    {
        Projectile p = {.active = false};
        game->projectiles[i] = p;
    }
}

void init_game(Game *game)
{
    create_projectile_pool(game);
    Player player;
    player_init(&player);
    game->player = player;
    game->projectile_count = 0;
}

void add_projectile(Game *game)
{
    for (int i = 0; i < POOl_SIZE - 2; i++)
    {
        if (!game->projectiles[i].active)
        {
            game->projectiles[i] = game->player.active_gun.bullet;
            break;
        }
    }
}

static void check_player_event(Game *game)
{
    if (game->player.event == PROJECTILE_FIRED)
    {
        add_projectile(game);
        TraceLog(LOG_INFO, "Firrrrrewwdd");
    }
    if (game->player.event == NONE)
    {
        TraceLog(LOG_INFO, "NONEE");
    }
}

static void update_projectile(Game *game)
{

    for (int i = 0; i < POOl_SIZE - 2; i++)
    {
        if (game->projectiles[i].active)
        {
            shoot_projectile(&game->projectiles[i]);
            render_projectile(&game->projectiles[i]);
        }
    }
}

void update_game(Game *game)
{
    update_player(&game->player);
    check_player_event(game);
    update_projectile(game);
}

void render_game(Game *game)
{
    render_player(&game->player);
}