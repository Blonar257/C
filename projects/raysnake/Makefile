CC := cc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS :=

PROJECT := raysnake
SRC_DIR := src
BIN_DIR := bin
TARGET := $(BIN_DIR)/$(PROJECT)

SRC := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/game.c \
	$(SRC_DIR)/ui.c \
	$(SRC_DIR)/highscore.c

OBJ := $(SRC:.c=.o)

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	RAYLIB_LIBS := -lraylib -lm -lpthread -ldl -lrt -lX11
else ifeq ($(UNAME_S),Darwin)
	RAYLIB_LIBS := -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework CoreVideo
else
	RAYLIB_LIBS := -lraylib
endif

.PHONY: all run clean debug release

all: $(TARGET)

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(RAYLIB_LIBS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

run: all
	./$(TARGET)

debug: CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O0 -g
debug: clean all

release: CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O3 -DNDEBUG
release: clean all

clean:
	rm -f $(OBJ)
	rm -rf $(BIN_DIR)
