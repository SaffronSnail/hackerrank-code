test: out.txt expected.txt
	diff out.txt expected.txt

out.txt: insert-sort-analysis.out in.txt
	./insert-sort-analysis.out < in.txt > out.txt

insert-sort-analysis.out:
	clang -Wall -Wextra -Werror -O3 -o insert-sort-analysis.out insert-sort-analysis.c
