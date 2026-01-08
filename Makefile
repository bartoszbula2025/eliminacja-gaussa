CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

SRC = src/main.c src/gauss.c src/backsubst.c src/mat_io.c
OBJ = $(SRC:.c=.o)

TARGET = gauss

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
