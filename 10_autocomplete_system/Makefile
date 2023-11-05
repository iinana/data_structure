CC = gcc
TARGET = main_exe
OBJECTS = Tries.o AutoComplete.o main.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^

run :
	./$(TARGET) input.txt output.txt

clean :
	rm *.o $(TARGET)