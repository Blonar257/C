#include "ui.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "raylib.h"

static float Clamp01(float v)
{
    if (v < 0.0f) return 0.0f;
    if (v > 1.0f) return 1.0f;
    return v;
}

static Color LerpColor(Color a, Color b, float t)
{
    t = Clamp01(t);
    Color out = {0};
    out.r = (unsigned char)(a.r + (b.r - a.r) * t);
    out.g = (unsigned char)(a.g + (b.g - a.g) * t);
    out.b = (unsigned char)(a.b + (b.b - a.b) * t);
    out.a = (unsigned char)(a.a + (b.a - a.a) * t);
    return out;
}

static void DrawSubtleVignette(int screenW, int screenH)
{
    Color transparent = {0, 0, 0, 0};
    Color dark = {0, 0, 0, 145};

    DrawRectangleGradientEx(
        (Rectangle){0, 0, (float)screenW, (float)screenH},
        transparent, transparent, dark, dark
    );

    DrawRectangleGradientEx(
        (Rectangle){0, 0, (float)screenW, (float)screenH},
        dark, dark, transparent, transparent
    );
}



void UI_InitStyle(UiStyle *style)
{
    if (!style) return;
    
    style->colors.bg = (Color){16, 18, 24, 255};
    style->colors.panel = (Color){24, 28, 36, 255};
    style->colors.panelBorder = (Color){48, 56, 72, 255};
    style->colors.textPrimary = (Color){232, 236, 245, 255};
    style->colors.textSecondary = (Color){145, 156, 178, 255};
    style->colors.accent = (Color){83, 181, 255, 255};
    style->colors.accentSoft = (Color){53, 130, 189, 255};
    style->colors.danger = (Color){230, 92, 92, 255};
    style->colors.hudBg = (Color){20, 22, 30, 220};
    style->colors.grid = (Color){34, 39, 50, 255};
    
    style->titleFontSize = 42;
    style->headingFontSize = 28;
    style->bodyFontSize = 20;
    style->smallFontSize = 16;
    style->panelRadius = 0.08f;
    style->panelBorderThickness = 2.0f;
    style->spacing = 16.0f;
}

MenuAction UI_DrawMainMenu(
    const UiStyle *style,
    int screenWidth,
    int screenHeight,
    int selectedIndex,
    int highscore
)
{
    if (!style) return MENU_ACTION_NONE;

    float t = (float)GetTime();

    ClearBackground(style->colors.bg);

    // Animated backdrop glow
    float pulse = (sinf(t * 1.3f) + 1.0f) * 0.5f;
    Color glowA = LerpColor(style->colors.accentSoft, style->colors.accent, pulse * 0.45f);
    glowA.a = 45;

    DrawCircleGradient(
        (int)(screenWidth * 0.25f),
        (int)(screenHeight * 0.20f),
        280.0f,
        glowA,
        (Color){0, 0, 0, 0}
    );

    DrawCircleGradient(
        (int)(screenWidth * 0.82f),
        (int)(screenHeight * 0.78f),
        300.0f,
        (Color){90, 120, 255, 30},
        (Color){0, 0, 0, 0}
    );

    // Main card
    Rectangle card = {
        (float)screenWidth * 0.5f - 260.0f,
        (float)screenHeight * 0.5f - 185.0f,
        520.0f,
        370.0f
    };

    DrawRectangleRounded(card, style->panelRadius, 12, style->colors.panel);
    DrawRectangleRoundedLinesEx(card, style->panelRadius, 12, style->panelBorderThickness, style->colors.panelBorder);

    // Title
    const char *title = "BLONAR SNAKE";
    int titleW = MeasureText(title, style->titleFontSize);
    DrawText(title, (int)(card.x + card.width * 0.5f - titleW * 0.5f), (int)card.y + 28, style->titleFontSize, style->colors.textPrimary);

    // Subtitle
    const char *subtitle = "Dark Neon Edition";
    int subtitleSize = 18;
    int subtitleW = MeasureText(subtitle, subtitleSize);
    DrawText(subtitle, (int)(card.x + card.width * 0.5f - subtitleW * 0.5f), (int)card.y + 76, subtitleSize, style->colors.textSecondary);

    // Highscore
    char highscoreText[128];
    snprintf(highscoreText, sizeof(highscoreText), "Highscore: %d", highscore);
    int hsW = MeasureText(highscoreText, style->headingFontSize);
    DrawText(highscoreText, (int)(card.x + card.width * 0.5f - hsW * 0.5f), (int)card.y + 118, style->headingFontSize, style->colors.accent);

    // Menu buttons
    const char *entries[2] = {"Neues Spiel", "Beenden"};
    const int totalEntries = 2;
    float btnW = 280.0f;
    float btnH = 52.0f;
    float startY = card.y + 170.0f;
    float spacing = 16.0f;

    MenuAction action = MENU_ACTION_NONE;

    for (int i = 0; i < totalEntries; ++i) {
        Rectangle btn = {
            card.x + card.width * 0.5f - btnW * 0.5f,
            startY + i * (btnH + spacing),
            btnW,
            btnH
        };

        bool selected = (selectedIndex == i);

        Color fill = selected ? LerpColor(style->colors.accentSoft, style->colors.accent, 0.35f) : (Color){30, 35, 46, 255};
        Color border = selected ? style->colors.accent : style->colors.panelBorder;
        Color text = selected ? style->colors.textPrimary : style->colors.textSecondary;

        DrawRectangleRounded(btn, 0.25f, 12, fill);
        DrawRectangleRoundedLinesEx(btn, 0.25f, 12, 2.0f, border);

        int fs = 26;
        int tw = MeasureText(entries[i], fs);
        DrawText(entries[i], (int)(btn.x + btn.width * 0.5f - tw * 0.5f), (int)(btn.y + btn.height * 0.5f - fs * 0.5f), fs, text);

        if (selected) {
            float tick = (sinf(t * 8.0f) + 1.0f) * 0.5f;
            Color marker = LerpColor(style->colors.accent, style->colors.textPrimary, tick * 0.35f);
            DrawCircle((int)(btn.x - 18), (int)(btn.y + btn.height * 0.5f), 6.0f, marker);
        }
    }

    // Check keyboard input
    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
        if (selectedIndex == 0) {
            action = MENU_ACTION_NEW_GAME;
        } else {
            action = MENU_ACTION_QUIT;
        }
    }

    const char *hint = "W/S oder Pfeile: Auswahl   |   ENTER: Bestätigen";
    int hintSize = 16;
    int hintW = MeasureText(hint, hintSize);
    DrawText(hint, (int)(card.x + card.width * 0.5f - hintW * 0.5f), (int)(card.y + card.height - 34), hintSize, style->colors.textSecondary);

    DrawSubtleVignette(screenWidth, screenHeight);

    return action;
}

void UI_DrawHud(
    const UiStyle *style,
    int screenWidth,
    int screenHeight,
    int score,
    int highscore
)
{
    if (!style) return;
    (void)screenHeight; // Suppress unused parameter warning

    Rectangle hud = {16, 14, (float)screenWidth - 32.0f, 56.0f};
    DrawRectangleRounded(hud, 0.25f, 12, style->colors.hudBg);
    DrawRectangleRoundedLinesEx(hud, 0.25f, 12, style->panelBorderThickness, style->colors.panelBorder);

    char scoreText[64];
    char highText[64];
    snprintf(scoreText, sizeof(scoreText), "Score: %d", score);
    snprintf(highText, sizeof(highText), "Highscore: %d", highscore);

    DrawText(scoreText, (int)hud.x + 18, (int)hud.y + 18, style->bodyFontSize, style->colors.textPrimary);

    int highW = MeasureText(highText, style->bodyFontSize);
    DrawText(highText, (int)(hud.x + hud.width - highW - 18), (int)hud.y + 18, style->bodyFontSize, style->colors.accent);
}

void UI_DrawGameOverOverlay(
    const UiStyle *style,
    int screenWidth,
    int screenHeight,
    int score,
    int highscore,
    bool isNewHighscore
)
{
    if (!style) return;
    (void)highscore; // Suppress unused parameter warning

    DrawRectangle(0, 0, screenWidth, screenHeight, (Color){0, 0, 0, 145});

    Rectangle panel = {
        (float)screenWidth * 0.5f - 220.0f,
        (float)screenHeight * 0.5f - 110.0f,
        440.0f,
        220.0f
    };

    DrawRectangleRounded(panel, style->panelRadius, 12, style->colors.panel);
    DrawRectangleRoundedLinesEx(panel, style->panelRadius, 12, style->panelBorderThickness, style->colors.panelBorder);

    const char *go = "GAME OVER";
    int goSize = 44;
    int goW = MeasureText(go, goSize);
    DrawText(go, (int)(panel.x + panel.width * 0.5f - goW * 0.5f), (int)panel.y + 30, goSize, style->colors.danger);

    char scoreStr[64];
    if (isNewHighscore) {
        snprintf(scoreStr, sizeof(scoreStr), "Neuer Highscore: %d!", score);
    } else {
        snprintf(scoreStr, sizeof(scoreStr), "Score: %d", score);
    }
    int scoreW = MeasureText(scoreStr, style->bodyFontSize);
    DrawText(scoreStr, (int)(panel.x + panel.width * 0.5f - scoreW * 0.5f), (int)panel.y + 90, style->bodyFontSize, style->colors.textSecondary);

    const char *restart = "ENTER: Neues Spiel   |   ESC: Menü";
    int rsSize = 18;
    int rsW = MeasureText(restart, rsSize);
    DrawText(restart, (int)(panel.x + panel.width * 0.5f - rsW * 0.5f), (int)panel.y + 140, rsSize, style->colors.textSecondary);
}

void UI_DrawCenteredText(
    const char *text,
    int y,
    int fontSize,
    Color color,
    int screenWidth
)
{
    if (!text) return;

    int textW = MeasureText(text, fontSize);
    DrawText(text, (int)(screenWidth * 0.5f - textW * 0.5f), y, fontSize, color);
}

Rectangle UI_GetCenteredPanel(
    int screenWidth,
    int screenHeight,
    float width,
    float height
)
{
    return (Rectangle){
        (float)screenWidth * 0.5f - width * 0.5f,
        (float)screenHeight * 0.5f - height * 0.5f,
        width,
        height
    };
}