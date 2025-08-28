# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -std=c11

# Libraries
LIBS = -lncurses

# Zielname
TARGET = todo

# Quellcode
SRC = main.c

# Standard-Regel: alles bauen
all: $(TARGET)

# Kompilieren
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

# Clean
clean:
	rm -f $(TARGET)

# Optional: rebuild
rebuild: clean all

