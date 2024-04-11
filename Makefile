WWW = -Wall -Werror -Wextra -lstdc++ -std=c++17
LINUX=-lsubunit -lrt -lpthread -lm
LIBS= -lgtest
LFLAGS=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)

all: clean test

re: clean all 

test: s21_matrix_oop.a clean_obj
ifeq ($(OS), Darwin)
	gcc $(WWW) unit_test.cc s21_matrix.a -o test $(LIBS)
else
	gcc $(WWW) unit_test.cc s21_matrix.a -o test $(LIBS) $(LINUX)
endif

s21_matrix_oop.a: build_s21_matrix 

build_s21_matrix:
	gcc $(FLAGS) -c s21_*.cc
	ar rcs s21_matrix.a s21_*.o
	ranlib s21_matrix.a

valgff: test
	valgrind --leak-check=full --track-origins=yes -s ./test

leaks: test
	leaks -atExit -- ./test

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n s21_matrix_oop.cc 
	clang-format -n s21_matrix_oop.h
	clang-format -n unit_test.cc

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean: clean_lib clean_obj
	rm -rf test
