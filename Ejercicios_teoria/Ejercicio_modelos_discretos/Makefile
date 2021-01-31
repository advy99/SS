HOME = .
SRC  = $(HOME)/src
BIN  = $(HOME)/bin
OBJ  = $(HOME)/obj
INC  = $(HOME)/include

CXXFLAGS = -O2 -std=c++17 -I$(INC)

.PHONY: all clean crear_carpetas

OBJETIVOS =  $(BIN)/main_inventario

all: crear_carpetas $(OBJETIVOS)

$(BIN)/main_inventario: $(OBJ)/main.o $(OBJ)/sistema_inventario.o
	g++ $(CXXFLAGS) $^ -o $@

$(OBJ)/main.o: $(SRC)/main.cpp
	g++ -c $(CXXFLAGS) $^ -o $@

$(OBJ)/sistema_inventario.o: $(SRC)/sistema_inventario.cpp
	g++ -c $(CXXFLAGS) $^ -o $@


crear_carpetas:
	-mkdir -p $(OBJ)
	-mkdir -p $(BIN)


clean:
	-rm $(OBJETIVOS)
	-rm $(OBJ)/*.o
