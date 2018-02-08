test: submission.out input.txt
	./submission.out < input.txt

submission.out: submission.cpp
	g++ -g -std=c++17 -Wall -Wextra -o $@ submission.cpp

clean:
	rm *.out

