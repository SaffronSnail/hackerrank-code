test: main.out in.txt expected.txt
	./main.out < in.txt > actual.txt
	diff expected.txt actual.txt

debug: main.out
	gdb ./main.out

main.out: main.c
	gcc -Wall -Wextra -Werror -g -o main.out main.c

