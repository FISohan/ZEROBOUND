
#ifndef GAME_H
#define GAME_H
#define POOl_SIZE 1002
#include "player.h"

typedef struct 
{
    Player player;
    //projectile array
    Projectile projectiles[POOl_SIZE];
    int projectile_count;
} Game;

void init_game(Game *game);
void render_game(Game *game);
void update_game(Game *game);
void add_projectile(Game *game);
void create_projectile_pool(Game *game);

#endif