FLAGS=-Wall -Wextra -Werror
DEBUG_FLAGS=-g

# TEST COMMANDS
test-brute: build/brute data/data.txt
	time ./build/brute < data/data.txt

test-calculate: build/calculate data/data.txt
	time ./build/calculate < data/data.txt

# EXECUTABLE COMMANDS
build/brute: build/main.o build/brute.o build/shared.o
	cc $(FLAGS) build/main.o build/brute.o build/shared.o -o build/brute

build/calculate: build/main.o build/calculate.o build/shared.o
	cc $(FLAGS) build/main.o build/calculate.o build/shared.o -o build/calculate

build/brute-debug: build/main-debug.o build/brute-debug.o build/shared-debug.o
	cc $(FLAGS) build/main-debug.o build/brute-debug.o build/shared-debug.o -o build/brute-debug

build/calculate-debug: build/main-debug.o build/calculate-debug.o build/shared-debug.o
	cc $(FLAGS) $(DEBUG_FLAGS) build/main-debug.o build/calculate-debug.o build/shared-debug.o -o build/calculate-debug

# OBJECT COMMANDS
build/brute.o: src/brute.c src/shared.h
	cc $(FLAGS) src/brute.c -c -o build/brute.o

build/calculate.o: src/calculate.c src/shared.h
	cc $(FLAGS) src/calculate.c -c -o build/calculate.o

build/main.o: src/main.c src/shared.h src/main.h
	cc $(FLAGS) src/main.c -c -o build/main.o

build/shared.o: src/shared.c src/shared.h
	cc $(FLAGS) src/shared.c -c -o build/shared.o

build/brute-debug.o: src/brute.c src/shared.h
	cc $(FLAGS) $(DEBUG_FLAGS) src/brute.c -c -o build/brute-debug.o

build/calculate-debug.o: src/calculate.c src/shared.h
	cc $(FLAGS) $(DEBUG_FLAGS) src/calculate.c -c -o build/calculate-debug.o

build/main-debug.o: src/main.c src/shared.h src/main.h
	cc $(FLAGS) $(DEBUG_FLAGS) src/main.c -c -o build/main-debug.o

build/shared-debug.o: src/shared.c src/shared.h
	cc $(FLAGS) $(DEBUG_FLAGS) src/shared.c -c -o build/shared-debug.o

