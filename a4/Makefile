CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
YACC = bison
LEX = flex

.PHONY: q1 q2 clean

q1: q1/q1.tab.c q1/lex.yy.c
	$(CXX) $(CXXFLAGS) q1/q1.tab.c q1/lex.yy.c -o q1/q1
	./q1/q1

q1/q1.tab.c: q1/q1.y
	cd q1 && $(YACC) -d q1.y

q1/lex.yy.c: q1/q1.l q1/q1.tab.c
	cd q1 && $(LEX) q1.l

q2:
	$(CXX) $(CXXFLAGS) q2/main.cpp -o q2/q2
	./q2/q2

clean:
	rm -f q1/q1 q1/q1.tab.c q1/q1.tab.h q1/lex.yy.c q2/q2
