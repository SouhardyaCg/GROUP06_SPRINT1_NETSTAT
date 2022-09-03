CC = g++

CCFLAGS = -c -g -Wall
LDFLAGS = -o
IFLAGS = -I

INC = inc
BIN = bin
OBJ = obj
SRC = src

all: firefox

firefox: $(OBJ)/main.o $(OBJ)/firefox.o
	$(CC) $(LDFLAGS) $(BIN)/firefox $(OBJ)/main.o $(OBJ)/firefox.o

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CCFLAGS) $(SRC)/main.cpp  $(IFLAGS) $(INC)/
	mv *.o $(OBJ)/
	
$(OBJ)/firefox.o: $(SRC)/firefox.cpp
	$(CC) $(CCFLAGS) $(SRC)/firefox.cpp  $(IFLAGS) $(INC)/ 
	mv *.o $(OBJ)/

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/firefox
	@echo "Cleaning Done!"
