CC = gcc
TARGET = main_exe
SRCDIR = ../hash
VPATH = $(SRCDIR):../practice

SOURCES = $(SRCDIR)/hashFIO.c function.c main.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

run:
	./$(TARGET) input.txt output.txt

clean:
	rm -f $(OBJECTS) $(TARGET)