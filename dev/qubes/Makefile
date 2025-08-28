# Compiler und Flags
CC = gcc
CFLAGS = -Wall -std=c99 -O2
LDFLAGS = -lraylib -lm -ldl -lpthread -lGL -lrt -lX11

# Projektdateien
SRC = main.c
OBJ = $(SRC:.c=.o)
OUT = game

# Build-Regeln
all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Aufräumen
clean:
	rm -f $(OBJ) $(OUT)

