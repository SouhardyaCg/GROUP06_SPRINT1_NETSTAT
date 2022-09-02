CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o
IFLAGS = -I

INC = inc
BIN = bin
OBJ = obj
SRC = src

all: cmd

cmd: $(OBJ)/main.o $(OBJ)/cmd.o
	$(CC) $(LDFLAGS) $(BIN)/cmd $(OBJ)/main.o $(OBJ)/cmd.o

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CCFLAGS) $(SRC)/main.cpp  $(IFLAGS) $(INC)/
	mv *.o $(OBJ)/
	
$(OBJ)/cmd.o: $(SRC)/cmd.cpp
	$(CC) $(CCFLAGS) $(SRC)/cmd.cpp  $(IFLAGS) $(INC)/ 
	mv *.o $(OBJ)/

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/cmd 
	@echo "Cleaning Done!"
