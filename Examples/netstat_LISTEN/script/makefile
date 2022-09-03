CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o
IFLAGS = -I

INC = inc
BIN = bin
OBJ = obj
SRC = src

all: listen

listen: $(OBJ)/main.o $(OBJ)/listen.o
	$(CC) $(LDFLAGS) $(BIN)/listen $(OBJ)/main.o $(OBJ)/listen.o

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CCFLAGS) $(SRC)/main.cpp  $(IFLAGS) $(INC)/
	mv *.o $(OBJ)/

$(OBJ)/listen.o: $(SRC)/listen.cpp
	$(CC) $(CCFLAGS) $(SRC)/listen.cpp  $(IFLAGS) $(INC)/
	mv *.o $(OBJ)/

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/listen
	@echo "Cleaning Done!"                           
