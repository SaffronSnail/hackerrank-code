test: submission.out input.txt
	./submission.out < input.txt

submission.out: submission.cpp
	clang++ -g -std=c++11 -Wall -Wextra -o $@ submission.cpp

clean:
	rm *.out

