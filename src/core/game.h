#include "player.h"

#ifndef GAME_H
#define GAME_H

typedef struct 
{
    Player player;
    //projectile array
} Game;

void init_game(Game *game);
void render_game(Game *game);
void update_game(Game *game);

#endif