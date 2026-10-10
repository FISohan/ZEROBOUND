
#ifndef GAME_H
#define GAME_H
#include "player.h"

typedef struct 
{
    Player player;
    //projectile array
    Projectile projectiles[10000];
    int projectile_count;
} Game;

void init_game(Game *game);
void render_game(Game *game);
void update_game(Game *game);
void add_projectile(Game *game);
#endif