#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

typedef struct {
    int x;
    int y;
} GridPos;

typedef struct GameState GameState;

/* Create a new game state */
GameState *game_create(void);

/* Destroy game state */
void game_destroy(GameState *game);

/* Reset game to initial state */
void game_reset(GameState *game);

/* Set board layout parameters */
void game_set_board_layout(GameState *game, int cellSize, int offsetX, int offsetY);

/* Set snake direction */
void game_set_direction(GameState *game, int dirX, int dirY);

/* Update game state */
void game_update(GameState *game, float dt);

/* Get score */
int game_get_score(const GameState *game);

/* Check if game is over */
bool game_is_game_over(const GameState *game);

/* Get grid dimensions */
int game_get_grid_width(void);
int game_get_grid_height(void);

/* Get snake info */
int game_get_snake_length(const GameState *game);
void game_get_snake_segment(const GameState *game, int index, int *x, int *y);

/* Get food position */
void game_get_food_position(const GameState *game, int *x, int *y);

/* Get layout info */
int game_get_cell_size(const GameState *game);
int game_get_offset_x(const GameState *game);
int game_get_offset_y(const GameState *game);

#endif /* GAME_H */