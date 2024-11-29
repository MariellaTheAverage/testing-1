CC = gcc
CXX = g++
CFLAGS = -Wall -Werror -Iapp
CXXFLAGS = -Iapp
LDFLAGS = --coverage
GTEST_DIR = googletest/googletest

SRC_DIR = app
TEST_DIR = tests

APP_SRCS = $(SRC_DIR)/main.c
TEST_SRCS = $(TEST_DIR)/test_my_function.cpp

all: app

app: $(APP_SRCS)
	$(CC) $(CFLAGS) -o eq_solver $(APP_SRCS)

test: $(TEST_SRCS) $(APP_SRCS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o eq_solver_tests $(TEST_SRCS) $(APP_SRCS) -I$(GTEST_DIR)/include -L$(GTEST_DIR)/lib -lgtest -lgtest_main -pthread
	./test_main

clean:
	rm -f eq_solver eq_solver_tests *.o *.gcda *.gcno *.gcov