CC=g++
CPPFLAGS=-c -g -Wall
LDFLAGS=-lcppunit
OBJ=obj/
SRC=src/
BIN=bin/
INCLUDE=inc/

all:test


test: $(OBJ)main.o $(OBJ)test.o $(OBJ)netstat_r.o $(OBJ)netstat_tcp.o $(OBJ)netstat_udp.o $(OBJ)netstat_listen.o $(OBJ)netstat_firefox.o
	$(CC) -o test $(OBJ)main.o $(OBJ)test.o  $(OBJ)netstat_r.o $(OBJ)netstat_tcp.o $(OBJ)netstat_udp.o $(OBJ)netstat_listen.o $(OBJ)netstat_firefox.o $(LDFLAGS)
	mv test $(BIN)

$(OBJ)main.o: $(SRC)main.cpp
	$(CC) $(CPPFLAGS) $(SRC)main.cpp -I $(INCLUDE)
	mv main.o $(OBJ)

$(OBJ)test.o: $(SRC)test.cpp
	$(CC) $(CPPFLAGS) $(SRC)test.cpp -I $(INCLUDE)
	mv test.o $(OBJ)

$(OBJ)netstat_r.o: $(SRC)netstat_r.cpp
	$(CC) $(CPPFLAGS) $(SRC)netstat_r.cpp -I $(INCLUDE)
	mv netstat_r.o $(OBJ)

$(OBJ)netstat_tcp.o: $(SRC)netstat_tcp.cpp
	$(CC) $(CPPFLAGS) $(SRC)netstat_tcp.cpp -I $(INCLUDE)
	mv netstat_tcp.o $(OBJ)

$(OBJ)netstat_udp.o: $(SRC)netstat_udp.cpp
	$(CC) $(CPPFLAGS) $(SRC)netstat_udp.cpp -I $(INCLUDE)
	mv netstat_udp.o $(OBJ)

$(OBJ)netstat_listen.o: $(SRC)netstat_listen.cpp
	$(CC) $(CPPFLAGS) $(SRC)netstat_listen.cpp -I $(INCLUDE)
	mv netstat_listen.o $(OBJ)

$(OBJ)netstat_firefox.o: $(SRC)netstat_firefox.cpp
	$(CC) $(CPPFLAGS) $(SRC)netstat_firefox.cpp -I $(INCLUDE)
	mv netstat_firefox.o $(OBJ)

valgrind: $(BIN)test
	valgrind --leak-check=full --show-reachable=yes	$(BIN)test 1>$(BIN)/valgrind.txt

clean:
	rm -f $(OBJ)*.o 
	rm -f $(BIN)test
	rm -f $(BIN)/valgrind.txt


