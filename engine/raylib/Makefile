# Variablen definieren
CC = gcc
CFLAGS = -Wall -std=c99 -Wno-missing-braces
LIBS = -lraylib -lwayland-client -lwayland-cursor -lwayland-egl -lxkbcommon -lGL -lm -lpthread -ldl -lrt

# Name der Ausgabedatei
TARGET = a.out

# Quelldateien
SRC = core_2d_camera.c

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)



	# default:
	# gcc main.c -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	# geht auch
