CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pthread -O3 -march=native
LDFLAGS = -pthread -lm

TARGET = sorting
SRC = main.c
OBJ = main.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all run clean
