CC = gcc
CFLAGS = -Wall -Wextra -fPIC -Isrc
LDFLAGS = -shared

TARGET = libcobs.so
SRC = src/cobs.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm -f $(TARGET)
