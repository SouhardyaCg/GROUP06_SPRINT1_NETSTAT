CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o
IFLAGS = -I

INC = inc
BIN = bin
OBJ = obj
SRC = src

all: tcp

tcp: $(OBJ)/main.o $(OBJ)/tcp.o
	$(CC) $(LDFLAGS) $(BIN)/tcp $(OBJ)/main.o $(OBJ)/tcp.o

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CCFLAGS) $(SRC)/main.cpp  $(IFLAGS) $(INC)/
	mv *.o $(OBJ)/
	
$(OBJ)/tcp.o: $(SRC)/tcp.cpp
	$(CC) $(CCFLAGS) $(SRC)/tcp.cpp  $(IFLAGS) $(INC)/ 
	mv *.o $(OBJ)/

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/tcp 
	@echo "Cleaning Done!"
