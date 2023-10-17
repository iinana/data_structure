CC = gcc
TARGET = main_exe
OBJECTS = basic.o traversal.o main.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^

run :
	./$(TARGET) input.txt output.txt

clean :
	rm *.o main_exe
