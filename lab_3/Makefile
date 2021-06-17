CXX = gcc

CFLAGS = -c -Wall -Werror -std=c99 -O0

FLAGS = -Wall -Werror -std=c99 -O0

OBJECTS = build/main.o 

.PHONY: clean all bin build run

all: bin build bin/key

bin/key: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/key

build/main.o: src/main.c
	$(CXX) $(CFLAGS) src/main.c -o build/main.o

build:
	mkdir -p build

bin:
	mkdir -p bin

clean:
	-rm -rf build bin

run:
	./bin/key