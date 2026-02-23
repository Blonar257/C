#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns the absolute path to the highscore file in the user's home directory.
 * The resulting path is written into out_path (null-terminated).
 * Returns 1 on success, 0 on failure.
 */
int highscore_get_path(char *out_path, size_t out_path_size);

/**
 * Loads highscore from disk.
 * Returns the loaded score, or 0 if file does not exist / invalid / error.
 */
int Highscore_Load(void);

/**
 * Saves highscore to disk.
 */
void Highscore_Save(int score);

/**
 * Compares current_score with stored highscore, updates file if current_score is higher.
 * Returns the resulting highscore (updated or previous).
 */
int Highscore_UpdateIfHigher(int currentHighscore, int newScore);

#ifdef __cplusplus
}
#endif

#endif /* HIGHSCORE_H */