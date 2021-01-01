HOME = .
BIN = $(HOME)/bin
INC = $(HOME)/include
OBJ = $(HOME)/obj
SRC = $(HOME)/src

CXXFLAGS = -I$(INC) -g -Wall -Wextra -Wpedantic -Wfloat-equal

.PHONY = all clean crear_carpetas


all: crear_carpetas $(BIN)/practica4


$(BIN)/practica4: $(OBJ)/main.o $(OBJ)/SIR.o
	g++ $(CXXFLAGS) -o $@ $^

$(OBJ)/main.o: $(SRC)/practica4.cpp
	g++ $(CXXFLAGS) -c -o $@ $^

$(OBJ)/SIR.o: $(SRC)/SIR.cpp
	g++ $(CXXFLAGS) -c -o $@ $^


crear_carpetas:
	-mkdir -p $(BIN)
	-mkdir -p $(OBJ)
	-mkdir -p $(SRC)
	-mkdir -p $(INC)


