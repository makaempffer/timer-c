CC = gcc
CFLAGS = -Wall -Iraylib/src -Lraylib/src -lraylib -lm

SOURCES = src/main.c src/timer.c src/button_data.c src/functions.c
HEADERS = src/constants.h src/timer.h src/button_data.h src/functions.h
EXECUTABLE = game

all: $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(SOURCES) $(HEADERS)
	$(CC) $(SOURCES) $(CFLAGS) -o $@

clean:
	rm -f $(EXECUTABLE)
