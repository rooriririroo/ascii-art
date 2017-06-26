
# compiler name
CPP=g++

# flags
F=-Wall -std=c++11

# binary
BIN=./build/ascii-art.app

# main
MAIN=./src/main.cpp

# headers
H=./src/headers

# library
LIB=./src/lib/bmp_reader.cpp ./src/lib/bmp_header.cpp ./src/lib/bmp_image.cpp ./src/lib/bmp_body.cpp

all: clean compile
clean:
	rm -rf build
	mkdir	build
compile:
	$(CPP) $(F) -o $(BIN) -I$(H) $(MAIN) $(LIB)
run:
	$(BIN)
valgrind:
	valgrind $(BIN)
run_socrates:
	$(BIN) in/socrates.bmp 1 2
valgrind_socrates:
	valgrind $(BIN) in/socrates.bmp 1 2
