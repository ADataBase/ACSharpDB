.PHONY: build docs

all: build


build:
	g++ sample.cpp -fdiagnostics-color -static-libstdc++ -std=c++17

docs:
	doxygen Doxyfile