FLAGS=-Wall -Wextra -Werror

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

# OBJECT COMMANDS
build/brute.o: src/brute.c src/shared.h
	cc $(FLAGS) src/brute.c -c -o build/brute.o

build/calculate.o: src/calculate.c src/shared.h
	cc $(FLAGS) src/calculate.c -c -o build/calculate.o

build/main.o: src/main.c src/shared.h src/main.h
	cc $(FLAGS) src/main.c -c -o build/main.o

build/shared.o: src/shared.c src/shared.h
	cc $(FLAGS) src/shared.c -c -o build/shared.o

