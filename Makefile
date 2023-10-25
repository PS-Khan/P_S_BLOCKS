CC=g++
CFLAGS = -Wall -g -O
SRC = src/main.cpp
OBJ = obj/main.o
LIB_SRC = src/S_block.cpp 
LIB_OBJ = obj/S_block.o   

TARGET = blocks

all : $(TARGET)

$(TARGET): $(OBJ) $(LIB_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJ): $(SRC)
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIB_OBJ): $(LIB_SRC)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	del /Q obj\*.o
	del /Q blocks.exe
	