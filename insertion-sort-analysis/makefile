test: out.txt expected.txt
	diff out.txt expected.txt

expected.txt: in.txt
	clojure insert-sort-anal.clj < in.txt > expected.txt

out.txt: insert-sort-analysis.out in.txt
	./insert-sort-analysis.out < in.txt > out.txt

insert-sort-analysis.out: insert-sort-analysis.c
	clang -Wall -Wextra -Werror -O3 -o insert-sort-analysis.out insert-sort-analysis.c
