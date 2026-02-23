#include "raylib.h"
#include "game.h"
#include "ui.h"
#include "highscore.h"

#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 720
#define WINDOW_TITLE  "RaySnake"

typedef enum AppState {
    APP_STATE_MENU = 0,
    APP_STATE_PLAYING,
    APP_STATE_GAME_OVER
} AppState;

static void ApplyGlobalVisuals(void)
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    SetTraceLogLevel(LOG_WARNING);
}

int main(void)
{
    ApplyGlobalVisuals();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    SetWindowMinSize(960, 540);
    SetTargetFPS(60);

    srand((unsigned int)time(NULL));

    UiStyle style;
    UI_InitStyle(&style);

    int highscore = Highscore_Load();

    GameState *game = game_create();
    if (!game) {
        CloseWindow();
        return 1;
    }

    // Set up board layout
    int gridW = game_get_grid_width();
    int cellSize = 24;
    int boardW = gridW * cellSize;
    int boardX = (SCREEN_WIDTH - boardW) / 2;
    int boardY = 80;
    game_set_board_layout(game, cellSize, boardX, boardY);

    AppState state = APP_STATE_MENU;
    int menuSelection = 0;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // Global "back to menu" from Game Over
        if (state == APP_STATE_GAME_OVER)
        {
            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
            {
                state = APP_STATE_MENU;
            }
        }

        switch (state)
        {
            case APP_STATE_MENU:
            {
                MenuAction action = UI_DrawMainMenu(
                    &style,
                    SCREEN_WIDTH,
                    SCREEN_HEIGHT,
                    menuSelection,
                    highscore
                );

                if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
                    menuSelection = (menuSelection - 1 + 2) % 2;
                }
                if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
                    menuSelection = (menuSelection + 1) % 2;
                }

                if (action == MENU_ACTION_NEW_GAME)
                {
                    game_reset(game);
                    state = APP_STATE_PLAYING;
                }
                else if (action == MENU_ACTION_QUIT)
                {
                    game_destroy(game);
                    CloseWindow();
                    return 0;
                }
            } break;

            case APP_STATE_PLAYING:
            {
                // Handle input
                int dirX = 0, dirY = 0;
                if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
                    dirX = 0; dirY = -1;
                }
                if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
                    dirX = 0; dirY = 1;
                }
                if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
                    dirX = -1; dirY = 0;
                }
                if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
                    dirX = 1; dirY = 0;
                }
                if (dirX != 0 || dirY != 0) {
                    game_set_direction(game, dirX, dirY);
                }

                // Update game
                game_update(game, dt);

                // Check game over
                if (game_is_game_over(game))
                {
                    int currentScore = game_get_score(game);
                    if (currentScore > highscore)
                    {
                        highscore = currentScore;
                        Highscore_Save(highscore);
                    }

                    state = APP_STATE_GAME_OVER;
                }
            } break;

            case APP_STATE_GAME_OVER:
            default:
                break;
        }

        BeginDrawing();
        {
            ClearBackground(style.colors.bg);

            if (state == APP_STATE_MENU)
            {
                // Menu is drawn by UI_DrawMainMenu which returns action
            }
            else if (state == APP_STATE_PLAYING || state == APP_STATE_GAME_OVER)
            {
                int grid_w = game_get_grid_width();
                int grid_h = game_get_grid_height();
                int cell_size = game_get_cell_size(game);

                int board_width = grid_w * cell_size;
                int board_height = grid_h * cell_size;
                int board_x = (SCREEN_WIDTH - board_width) / 2;
                int board_y = 80;

                DrawRectangle(board_x, board_y, board_width, board_height, style.colors.panel);

                int snake_len = game_get_snake_length(game);
                for (int i = 0; i < snake_len; i++)
                {
                    int x, y;
                    game_get_snake_segment(game, i, &x, &y);
                    int px = board_x + x * cell_size;
                    int py = board_y + y * cell_size;
                    
                    Color seg_color = (i == 0) ? (Color){100, 217, 255, 255} : (Color){70, 168, 214, 255};
                    DrawRectangle(px, py, cell_size, cell_size, seg_color);
                }

                int food_x, food_y;
                game_get_food_position(game, &food_x, &food_y);
                if (food_x >= 0 && food_y >= 0)
                {
                    int fx = board_x + food_x * cell_size + cell_size / 2;
                    int fy = board_y + food_y * cell_size + cell_size / 2;
                    DrawCircle(fx, fy, cell_size / 3, (Color){255, 99, 146, 255});
                }

                UI_DrawHud(&style, SCREEN_WIDTH, SCREEN_HEIGHT, game_get_score(game), highscore);

                if (state == APP_STATE_GAME_OVER)
                {
                    bool is_new_highscore = (game_get_score(game) > highscore);
                    UI_DrawGameOverOverlay(
                        &style,
                        SCREEN_WIDTH,
                        SCREEN_HEIGHT,
                        game_get_score(game),
                        highscore,
                        is_new_highscore
                    );
                }
            }
        }
        EndDrawing();
    }

    Highscore_Save(highscore);
    game_destroy(game);
    CloseWindow();
    return 0;
}