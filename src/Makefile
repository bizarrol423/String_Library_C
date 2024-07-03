OS=$(shell uname)
ifeq ($(OS), Linux)
 LIBS=-lcheck -lpthread -lrt -lm -lsubunit
 OPEN=xdg-open
 LEAKS=CK_FORK=no valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./test.out
else
 LIBS=-lcheck
 OPEN=open
 LEAKS=CK_FORK=no leaks --atExit -- ./test.out
endif

all: s_string.a cpplint test cppcheck

s_str.o: s_string.c s_string.h
	gcc -c s_string.c

test:
	gcc s_string_tests.c s_string.c -o s_test -lcheck

gcov_report: 
	gcc --coverage s_string_tests.c s_string.c -o s_test -lcheck
	./s_test
	lcov -t s_test -o test.info -c -d .
	genhtml -o report test.info

s_string.a : s_str.o
	ar -cr s_string.a s_string.o

val :
	gcc -O0 -g s_string_tests.c -o vgcheck
	valgrind ./vgcheck --leak-check=full

cpplint:
	python3 ../materials/linters/cpplint.py --extensions=c *.c

leaks: test
	leaks -atExit -- ./s_test

cppcheck:
	cppcheck *;

clean: 
	rm -Rf *.o
	rm -Rf *.out
	rm -Rf *.gcda
	rm -Rf *.gcno
	rm -Rf report
	rm -Rf *.a
	rm -Rf *.info
	rm -Rf s_test
	rm -Rf main
	rm -Rf main.c

