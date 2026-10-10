

#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "gun.h"
typedef struct
{
    Vector2 position;
    Vector2 aim_position;
    Gun guns[10];
    Gun active_gun;

} Player;

void player_init(Player *player);
void render_player(Player *player);
void update_player(Player *player);
void fire_gun(Player *player);

#endif