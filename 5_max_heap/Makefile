CC = gcc
TARGET = main_exe
OBJECTS = basic_func.o main_func.o main.o

all : $(TARGET) 

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^

run :
	./$(TARGET) input.txt output.txt

clean :
	rm *.o main_exe