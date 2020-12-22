HOME = .
SRC  = $(HOME)/src
BIN  = $(HOME)/bin
INC  = $(HOME)/include
OBJ  = $(HOME)/obj

CXXFLAGS = -std=c++17 -I$(INC)

.PHONY: all clean

OBJETIVOS =  $(BIN)/reparadores $(BIN)/puerto $(BIN)/sistema_tiempo_variable \
				 $(BIN)/sistema_tiempo_fijo $(BIN)/reparadores_mantenimiento


all: $(OBJETIVOS)


$(BIN)/sistema_tiempo_variable: $(SRC)/sistema_tiempo_variable.cpp
	g++ $(CXXFLAGS) $^ -o $@

$(BIN)/sistema_tiempo_fijo: $(SRC)/sistema_tiempo_fijo.cpp
	g++ $(CXXFLAGS) $^ -o $@

$(BIN)/reparadores: $(SRC)/reparadores.cpp
	g++ $(CXXFLAGS) $^ -o $@

$(BIN)/reparadores_mantenimiento: $(SRC)/reparadores_mantenimiento.cpp
	g++ $(CXXFLAGS) $^ -o $@

$(BIN)/puerto: $(SRC)/puerto.cpp
	g++ $(CXXFLAGS) $^ -o $@

clean:
	-rm $(BIN)/*
	-rm $(OBJ)/*
