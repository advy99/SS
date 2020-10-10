HOME = .
SRC  = $(HOME)/src
BIN  = $(HOME)/bin


CXXFLAGS = -std=c++17

.PHONY: all clean

OBJETIVOS =  $(BIN)/aparcamiento $(BIN)/radares $(BIN)/lago

all: $(OBJETIVOS)

$(BIN)/aparcamiento: $(SRC)/aparcamiento.cpp
	g++ $(CXXFLAGS) $^ -o $@

$(BIN)/radares: $(SRC)/radares.cpp
	g++ $(CXXFLAGS) $^ -o $@

$(BIN)/lago: $(SRC)/Simulacion_lago2especiespeces.C
	g++ $(CXXFLAGS) $^ -o $@

clean:
	-rm $(OBJETIVOS)
