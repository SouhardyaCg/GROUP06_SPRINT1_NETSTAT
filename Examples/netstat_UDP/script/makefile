CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o
IFLAGS = -I

INC = inc
BIN = bin
OBJ = obj
SRC = src

all: udp

udp: $(OBJ)/main.o $(OBJ)/udp.o
	$(CC) $(LDFLAGS) $(BIN)/udp $(OBJ)/main.o $(OBJ)/udp.o

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CCFLAGS) $(SRC)/main.cpp  $(IFLAGS) $(INC)/
	mv *.o $(OBJ)/
	
$(OBJ)/udp.o: $(SRC)/udp.cpp
	$(CC) $(CCFLAGS) $(SRC)/udp.cpp  $(IFLAGS) $(INC)/ 
	mv *.o $(OBJ)/

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/udp
	@echo "Cleaning Done!"
