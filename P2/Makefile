HOME = .
SRC  = $(HOME)/src
BIN  = $(HOME)/bin
INC  = $(HOME)/include
OBJ  = $(HOME)/obj

CXXFLAGS = -std=c++17 -g -I$(INC)

.PHONY: all clean

OBJETIVOS =  $(BIN)/quiosco $(BIN)/mejora1_generadores \
				 $(BIN)/mejora2_generadores $(BIN)/mejora3_generadores

all: $(OBJETIVOS)

$(BIN)/quiosco: $(SRC)/quiosco.cpp $(OBJ)/codigo_generadores.o
	g++ $(CXXFLAGS) $^ -o $@

$(BIN)/mejora1_generadores: $(SRC)/mejora1_generadores.cpp \
								 	 $(OBJ)/codigo_generadores.o
	g++ $(CXXFLAGS) $^ -o $@

$(BIN)/mejora2_generadores: $(SRC)/mejora2_generadores.cpp \
								 	 $(OBJ)/codigo_generadores.o
	g++ $(CXXFLAGS) $^ -o $@

$(BIN)/mejora3_generadores: $(SRC)/mejora3_generadores.cpp \
								 	 $(OBJ)/codigo_generadores.o
	g++ $(CXXFLAGS) $^ -o $@

$(OBJ)/codigo_generadores.o: $(SRC)/codigo_generadores.cpp
	g++ $(CXXFLAGS) -c $^ -o $@

clean:
	-rm $(OBJETIVOS)
	-rm $(OBJ)/*.o
