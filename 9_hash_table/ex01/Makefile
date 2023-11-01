CC = gcc
TARGET = lookUp_exe
SRCDIR = ../hash
VPATH = $(SRCDIR):../ex01

SOURCES = $(SRCDIR)/hash.c lookUp.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

run:
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)