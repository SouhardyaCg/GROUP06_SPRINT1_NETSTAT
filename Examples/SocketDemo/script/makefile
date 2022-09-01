CC=g++
CPPFLAGS = -c -g -Wall
LDFLAGS = -o
IFLAGS = -I
OBJ = obj
SRC = src
BIN = bin/
INCLUDE = inc/

all: server client

server: $(OBJ)/mainServer.o $(OBJ)/func.o $(OBJ)/sock.o
	$(CC) $(LDFLAGS) $(BIN)/server $(OBJ)/mainServer.o $(OBJ)/func.o $(OBJ)/sock.o
#	v serveri$(BIN)/
$(OBJ)/mainServer.o: $(SRC)/mainServer.cpp
	$(CC) $(CPPFLAGS) $(SRC)/mainServer.cpp $(IFLAGS) $(INCLUDE)
	mv *.o $(OBJ)/
$(OBJ)/func.o : $(SRC)/func.cpp
	$(CC) $(CPPFLAGS) $(SRC)/func.cpp $(IFLAGS) $(INCLUDE)
	mv *.o $(OBJ)/
$(OBJ)/sock.o : $(SRC)/sock.cpp
	$(CC) $(CPPFLAGS) $(SRC)/sock.cpp $(IFLAGS) $(INCLUDE)
	mv *.o $(OBJ)/
client: $(OBJ)/mainClient.o $(OBJ)/func.o $(OBJ)/sock.o
	$(CC) $(LDFLAGS) $(BIN)/client $(OBJ)/mainClient.o $(OBJ)/func.o $(OBJ)/sock.o
#	mv client $(BIN)/
$(OBJ)/mainClient.o: $(SRC)/mainClient.cpp
	 $(CC) $(CPPFLAGS) $(SRC)/mainClient.cpp $(IFLAGS) $(INCLUDE)
	 mv *.o $(OBJ)/

valgrindServer : $(BIN)/server
	valgrind --leak-check=full --show-reachable=yes $(BIN)server 1>$(BIN)/valgrind_s.txt
valgrindClient : $(BIN)/client
	valgrind --leak-check=full --show-reachable=yes $(BIN)client 1>$(BIN)/valgrind_c.txt
clean:
#	rm a.out *.o
	rm $(OBJ)/*.o
	rm $(BIN)/server $(BIN)/client
	rm -f $(BIN)/valgrind_s.txt
	rm -f $(BIN)/valgrind_c.txt
	@echo "cleaning done"


