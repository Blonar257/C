#include "game.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRID_WIDTH 30
#define GRID_HEIGHT 20
#define MAX_SNAKE_LENGTH (GRID_WIDTH * GRID_HEIGHT)
#define BASE_MOVE_INTERVAL 0.14f
#define MIN_MOVE_INTERVAL 0.06f
#define SPEED_STEP 0.004f
#define SCORE_PER_FOOD 10

struct GameState {
    GridPos snake[MAX_SNAKE_LENGTH];
    int snakeLength;

    GridPos food;
    bool foodActive;

    GridPos direction;
    GridPos pendingDirection;

    int score;
    bool gameOver;

    float moveTimer;
    float moveInterval;

    int cellSize;
    int offsetX;
    int offsetY;
};

static bool positions_equal(GridPos a, GridPos b) {
    return a.x == b.x && a.y == b.y;
}

static bool is_inside_grid(GridPos p) {
    return p.x >= 0 && p.x < GRID_WIDTH && p.y >= 0 && p.y < GRID_HEIGHT;
}

static bool snake_contains(const GameState *game, GridPos p, int ignoreTail) {
    int limit = game->snakeLength - (ignoreTail ? 1 : 0);
    if (limit < 0) limit = 0;

    for (int i = 0; i < limit; ++i) {
        if (positions_equal(game->snake[i], p)) {
            return true;
        }
    }
    return false;
}

static GridPos random_free_cell(const GameState *game) {
    int freeCount = GRID_WIDTH * GRID_HEIGHT - game->snakeLength;
    if (freeCount <= 0) {
        GridPos fallback = {0, 0};
        return fallback;
    }

    int target = rand() % freeCount;
    int index = 0;

    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            GridPos p = {x, y};
            if (!snake_contains(game, p, 0)) {
                if (index == target) {
                    return p;
                }
                index++;
            }
        }
    }

    GridPos fallback = {0, 0};
    return fallback;
}

static void spawn_food(GameState *game) {
    game->food = random_free_cell(game);
    game->foodActive = true;
}

static void reset_snake(GameState *game) {
    game->snakeLength = 3;

    int startX = GRID_WIDTH / 2;
    int startY = GRID_HEIGHT / 2;

    game->snake[0] = (GridPos){startX, startY};
    game->snake[1] = (GridPos){startX - 1, startY};
    game->snake[2] = (GridPos){startX - 2, startY};

    game->direction = (GridPos){1, 0};
    game->pendingDirection = game->direction;
}

static bool is_reverse(GridPos current, GridPos next) {
    return current.x == -next.x && current.y == -next.y;
}

GameState *game_create(void) {
    static bool seeded = false;
    if (!seeded) {
        seeded = true;
        srand((unsigned int)time(NULL));
    }

    GameState *game = (GameState *)calloc(1, sizeof(GameState));
    if (!game) {
        return NULL;
    }

    game->cellSize = 28;
    game->offsetX = 0;
    game->offsetY = 0;

    game_reset(game);
    return game;
}

void game_destroy(GameState *game) {
    free(game);
}

void game_reset(GameState *game) {
    if (!game) return;

    reset_snake(game);
    game->score = 0;
    game->gameOver = false;
    game->moveTimer = 0.0f;
    game->moveInterval = BASE_MOVE_INTERVAL;

    spawn_food(game);
}

void game_set_board_layout(GameState *game, int cellSize, int offsetX, int offsetY) {
    if (!game) return;
    game->cellSize = cellSize;
    game->offsetX = offsetX;
    game->offsetY = offsetY;
}

void game_set_direction(GameState *game, int dirX, int dirY) {
    if (!game) return;
    if (game->gameOver) return;

    GridPos next = {dirX, dirY};
    if ((next.x == 0 && next.y == 0) || (abs(next.x) + abs(next.y) != 1)) {
        return;
    }

    if (is_reverse(game->direction, next)) {
        return;
    }

    game->pendingDirection = next;
}

static void step_snake(GameState *game) {
    game->direction = game->pendingDirection;

    GridPos head = game->snake[0];
    GridPos nextHead = {head.x + game->direction.x, head.y + game->direction.y};

    if (!is_inside_grid(nextHead)) {
        game->gameOver = true;
        return;
    }

    bool willEat = game->foodActive && positions_equal(nextHead, game->food);

    if (snake_contains(game, nextHead, willEat ? 0 : 1)) {
        game->gameOver = true;
        return;
    }

    if (willEat) {
        if (game->snakeLength < MAX_SNAKE_LENGTH) {
            for (int i = game->snakeLength; i > 0; --i) {
                game->snake[i] = game->snake[i - 1];
            }
            game->snake[0] = nextHead;
            game->snakeLength++;
        } else {
            for (int i = game->snakeLength - 1; i > 0; --i) {
                game->snake[i] = game->snake[i - 1];
            }
            game->snake[0] = nextHead;
        }

        game->score += SCORE_PER_FOOD;
        game->moveInterval -= SPEED_STEP;
        if (game->moveInterval < MIN_MOVE_INTERVAL) {
            game->moveInterval = MIN_MOVE_INTERVAL;
        }

        if (game->snakeLength >= MAX_SNAKE_LENGTH) {
            game->gameOver = true;
            return;
        }

        spawn_food(game);
    } else {
        for (int i = game->snakeLength - 1; i > 0; --i) {
            game->snake[i] = game->snake[i - 1];
        }
        game->snake[0] = nextHead;
    }
}

void game_update(GameState *game, float dt) {
    if (!game || game->gameOver) return;

    game->moveTimer += dt;
    while (game->moveTimer >= game->moveInterval) {
        game->moveTimer -= game->moveInterval;
        step_snake(game);
        if (game->gameOver) {
            break;
        }
    }
}

int game_get_score(const GameState *game) {
    return game ? game->score : 0;
}

bool game_is_game_over(const GameState *game) {
    return game ? game->gameOver : true;
}

int game_get_grid_width(void) {
    return GRID_WIDTH;
}

int game_get_grid_height(void) {
    return GRID_HEIGHT;
}

int game_get_snake_length(const GameState *game) {
    return game ? game->snakeLength : 0;
}

void game_get_snake_segment(const GameState *game, int index, int *x, int *y) {
    if (!game || index < 0 || index >= game->snakeLength) {
        if (x) *x = 0;
        if (y) *y = 0;
        return;
    }

    if (x) *x = game->snake[index].x;
    if (y) *y = game->snake[index].y;
}

void game_get_food_position(const GameState *game, int *x, int *y) {
    if (!game || !game->foodActive) {
        if (x) *x = -1;
        if (y) *y = -1;
        return;
    }

    if (x) *x = game->food.x;
    if (y) *y = game->food.y;
}

int game_get_cell_size(const GameState *game) {
    return game ? game->cellSize : 0;
}

int game_get_offset_x(const GameState *game) {
    return game ? game->offsetX : 0;
}

int game_get_offset_y(const GameState *game) {
    return game ? game->offsetY : 0;
}