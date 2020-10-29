HOME = .
SRC  = $(HOME)/src
BIN  = $(HOME)/bin
INC  = $(HOME)/include
OBJ  = $(HOME)/obj

CXXFLAGS = -std=c++17 -I$(INC)

.PHONY: all clean

OBJETIVOS =  $(BIN)/quiosco

all: $(OBJETIVOS)

$(BIN)/quiosco: $(SRC)/quiosco.cpp $(OBJ)/codigo_generadores.o
	g++ $(CXXFLAGS) $^ -o $@


$(OBJ)/codigo_generadores.o: $(SRC)/codigo_generadores.cpp
	g++ $(CXXFLAGS) -c $^ -o $@

clean:
	-rm $(OBJETIVOS)
