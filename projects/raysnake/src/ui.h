#ifndef UI_H
#define UI_H

#include "raylib.h"
#include "game.h"

typedef struct {
    Color bg;
    Color panel;
    Color panelBorder;
    Color textPrimary;
    Color textSecondary;
    Color accent;
    Color accentSoft;
    Color danger;
    Color hudBg;
    Color grid;
} UiColors;

typedef struct {
    UiColors colors;
    int titleFontSize;
    int headingFontSize;
    int bodyFontSize;
    int smallFontSize;
    float panelRadius;
    float panelBorderThickness;
    float spacing;
} UiStyle;

typedef enum MenuAction {
    MENU_ACTION_NONE = 0,
    MENU_ACTION_NEW_GAME,
    MENU_ACTION_QUIT
} MenuAction;

/* Initializes style values (dark/modern default palette). */
void UI_InitStyle(UiStyle *style);

/* Draws the main menu and returns user action when selected. */
MenuAction UI_DrawMainMenu(
    const UiStyle *style,
    int screenWidth,
    int screenHeight,
    int selectedIndex,
    int highscore
);

/* Draws in-game HUD (score, highscore, hints). */
void UI_DrawHud(
    const UiStyle *style,
    int screenWidth,
    int screenHeight,
    int score,
    int highscore
);

/* Draws game-over overlay and restart hint. */
void UI_DrawGameOverOverlay(
    const UiStyle *style,
    int screenWidth,
    int screenHeight,
    int score,
    int highscore,
    bool isNewHighscore
);

/* Utility helpers */
void UI_DrawCenteredText(
    const char *text,
    int y,
    int fontSize,
    Color color,
    int screenWidth
);

Rectangle UI_GetCenteredPanel(
    int screenWidth,
    int screenHeight,
    float width,
    float height
);

#endif /* UI_H */