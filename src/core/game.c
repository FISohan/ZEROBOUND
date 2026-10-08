
#include "game.h"
#include "player.h"

void init_game(Game *game){
    Player player;
    player_init(&player);
    game->player = player;
}

void update_game(Game *game){
    update_player(&game->player);
}

void render_game(Game *game){
    rendar_player(&game->player);
}