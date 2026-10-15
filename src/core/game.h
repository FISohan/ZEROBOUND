
#ifndef GAME_H
#define GAME_H
#define POOl_SIZE 1002
#define MAX_ENEMY_COUNT 100
#include "player.h"
#include "enemy.h"

typedef struct 
{
    Player player;
    //projectile array
    Projectile projectiles[POOl_SIZE];
    Enemy enemies[MAX_ENEMY_COUNT];
    int enemy_count;
} Game;

void init_game(Game *game);
void render_game(Game *game);
void update_game(Game *game);

void add_projectile(Game *game);
void create_projectile_pool(Game *game);

void chase_player(Game *game);
void spwan_enemy(Game *game);
#endif