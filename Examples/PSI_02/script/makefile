CC=g++
CPPFLAGS = -c -g -Wall
LDFLAGS = -o
IFLAGS = -I
OBJ = obj
SRC = src
BIN = bin/
INCLUDE = inc/

all: server client 

server: $(OBJ)/mainServer.o $(OBJ)/server.o $(OBJ)/cmd.o
	$(CC) $(LDFLAGS) $(BIN)/server $(OBJ)/mainServer.o $(OBJ)/server.o $(OBJ)/cmd.o

$(OBJ)/mainServer.o: $(SRC)/mainServer.cpp 
	$(CC) $(CPPFLAGS) $(SRC)/mainServer.cpp $(IFLAGS) $(INCLUDE)
	mv *.o $(OBJ)/

$(OBJ)/server.o : $(SRC)/server.cpp
	$(CC) $(CPPFLAGS) $(SRC)/server.cpp $(IFLAGS) $(INCLUDE)
	mv *.o $(OBJ)/

$(OBJ)/cmd.o : $(SRC)/cmd.cpp
	$(CC) $(CPPFLAGS) $(SRC)/cmd.cpp $(IFLAGS) $(INCLUDE)
	mv *.o $(OBJ)/


client: $(OBJ)/mainClient.o $(OBJ)/client.o
	$(CC) $(LDFLAGS) $(BIN)/client $(OBJ)/mainClient.o $(OBJ)/client.o

$(OBJ)/mainClient.o: $(SRC)/mainClient.cpp
	$(CC) $(CPPFLAGS) $(SRC)/mainClient.cpp $(IFLAGS) $(INCLUDE)
	mv *.o $(OBJ)/

$(OBJ)/client.o : $(SRC)/client.cpp
	$(CC) $(CPPFLAGS) $(SRC)/client.cpp $(IFLAGS) $(INCLUDE)
	mv *.o $(OBJ)/


valgrindServer : $(BIN)/server
	valgrind --leak-check=full --show-reachable=yes $(BIN)server 1>$(BIN)/valgrind_s.txt
valgrindClient : $(BIN)/client
	valgrind --leak-check=full --show-reachable=yes $(BIN)client 1>$(BIN)/valgrind_c.txt

clean:
	rm a.out *.o
	rm $(OBJ)/*.o
	rm $(BIN)/server $(BIN)/client
	rm -f $(BIN)/valgrind_s.txt
	rm -f $(BIN)/valgrind_c.txt
	@echo "cleaning done"
