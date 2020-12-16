HOME = .
SRC  = $(HOME)/src
BIN  = $(HOME)/bin
INC  = $(HOME)/include
OBJ  = $(HOME)/obj

CXXFLAGS = -std=c++17 -I$(INC)

.PHONY: all clean

OBJETIVOS =  $(BIN)/reparadores $(BIN)/puerto


all: $(OBJETIVOS)


$(BIN)/reparadores: $(SRC)/reparadores.cpp
	g++ $(CXXFLAGS) $^ -o $@

$(BIN)/puerto: $(SRC)/puerto.cpp
	g++ $(CXXFLAGS) $^ -o $@

