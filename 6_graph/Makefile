CC = gcc
TARGET = main_exe
OBJECTS = basic_func.o traversal.o queue.o main.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^

run :
	./$(TARGET) input.txt output.txt

clean :
	rm *.o main_exe
