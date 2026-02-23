#include "highscore.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#define HIGHSCORE_FILENAME ".raysnake_highscore"

static int get_highscore_path(char *outPath, size_t outSize)
{
    const char *home = getenv("HOME");
    if (!home || home[0] == '\0')
    {
        return 0;
    }

    int written = snprintf(outPath, outSize, "%s/%s", home, HIGHSCORE_FILENAME);
    if (written < 0 || (size_t)written >= outSize)
    {
        return 0;
    }

    return 1;
}

int Highscore_Load(void)
{
    char path[PATH_MAX];
    if (!get_highscore_path(path, sizeof(path)))
    {
        return 0;
    }

    FILE *file = fopen(path, "r");
    if (!file)
    {
        return 0;
    }

    int score = 0;
    if (fscanf(file, "%d", &score) != 1)
    {
        fclose(file);
        return 0;
    }

    fclose(file);

    if (score < 0)
    {
        return 0;
    }

    return score;
}

void Highscore_Save(int score)
{
    if (score < 0)
    {
        score = 0;
    }

    char path[PATH_MAX];
    if (!get_highscore_path(path, sizeof(path)))
    {
        return;
    }

    FILE *file = fopen(path, "w");
    if (!file)
    {
        return;
    }

    fprintf(file, "%d\n", score);
    fclose(file);
}

int Highscore_UpdateIfHigher(int currentHighscore, int newScore)
{
    if (newScore > currentHighscore)
    {
        Highscore_Save(newScore);
        return newScore;
    }

    return currentHighscore;
}

int highscore_get_path(char *out_path, size_t out_path_size)
{
    return get_highscore_path(out_path, out_path_size);
}