#include "raylib.h"

#ifndef PLAYER_H
#define PLAYER_H

typedef struct
{
    Vector2 position;
} Player;

void player_init(Player *player);
void rendar_player(Player *player);
void update_player(Player *player);

#endif