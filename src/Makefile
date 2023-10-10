.PHONY: all clean test

CC=g++
FLAGS=-Wall -Wextra -Werror -std=c++17
LFLAG=-lgtest -lgmock -pthread
GCOVFLAGS=--coverage -g -O0 

LIBNAME=s21_matrix_oop
GCOVNAME=coverage
#-fsanitize=address

SRCS=$(wildcard *.cc)

all: s21_matrix_oop.a

$(LIBNAME).a:
	$(CC) $(FLAGS) -c $(SRCS)
	ar rc s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a
	rm *.o

debug:
	$(CC) $(FLAGS) -g $(SRCS) 
	./a.out

test: $(LIBNAME).a
	$(CC) $(FLAGS) -g $(LFLAG) $(LIBNAME).a tests/main.cpp -o test
	./test

gcov_report: add_coverage_flag
	$(CC) $(FLAGS) $(LFLAG) $(GCOVFLAGS) $(SRCS) tests/main.cpp -o gcov_main
	./gcov_main
	gcovr --exclude-unreachable-branches --html-details coverage.html
	open coverage.html

clean:
	rm -rf *.out build/ *dSYM/ *.o *.a test
	rm -rf gcov_report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov_main test

add_coverage_flag:
	$(eval FLAGS += --coverage)

style:
	cp ../materials/linters/.clang-format ./
	# clang-format -i *.cc *.h
	clang-format -n *.cc *.h
	rm .clang-format
