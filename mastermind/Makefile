# Compilateur et options
CC      = gcc
CFLAGS  = -Wall -Wextra -Wpedantic -std=c11

# Dossier pour les .o et l'exécutable
BIN_DIR = bin

# Tous les fichiers .c du dossier courant
SRC     = $(wildcard *.c)

# Transformation : foo.c -> bin/foo.o
OBJ     = $(patsubst %.c,$(BIN_DIR)/%.o,$(SRC))

# Nom de l'exécutable
TARGET  = $(BIN_DIR)/mastermind

# Règle par défaut
all: $(TARGET)

# Lien de l'exécutable
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Règle générique de compilation : .c -> bin/.o
$(BIN_DIR)/%.o: %.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean
