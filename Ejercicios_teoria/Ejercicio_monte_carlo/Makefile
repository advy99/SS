HOME = .
SRC  = $(HOME)/src
BIN  = $(HOME)/bin
OBJ  = $(HOME)/obj
INC  = $(HOME)/include

CXXFLAGS = -std=c++17 -I$(INC)

.PHONY: all clean crear_carpetas

OBJETIVOS =  $(BIN)/main_reciclar

all: crear_carpetas $(OBJETIVOS)

$(BIN)/main_reciclar: $(OBJ)/main.o $(OBJ)/planta_reciclaje.o
	g++ $(CXXFLAGS) $^ -o $@

$(OBJ)/main.o: $(SRC)/main.cpp
	g++ -c $(CXXFLAGS) $^ -o $@

$(OBJ)/planta_reciclaje.o: $(SRC)/planta_reciclaje.cpp
	g++ -c $(CXXFLAGS) $^ -o $@


crear_carpetas:
	-mkdir -p $(OBJ)
	-mkdir -p $(BIN)


clean:
	-rm $(OBJETIVOS)
	-rm $(OBJ)/*.o
