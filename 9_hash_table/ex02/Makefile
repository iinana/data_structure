CC = gcc
TARGET = subset_exe
SRCDIR = ../hash
VPATH = $(SRCDIR):../ex02

SOURCES = $(SRCDIR)/hash.c subset.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

run:
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)