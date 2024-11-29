CC = gcc
CXX = g++
CFLAGS = -Wall -Werror -Iapp
CXXFLAGS = --std=c++17 -Iapp
LDFLAGS = --coverage
GTEST_DIR = googletest/googletest

SRC_DIR = app
TEST_DIR = tests

APP_SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/func.c
APP_HEAD = $(SRC_DIR)/main.h
TEST_SRCS = $(TEST_DIR)/main.cpp

all: app

gtest-build:
	mkdir -p $(GTEST_DIR)/build
	cd $(GTEST_DIR)/build && cmake .. && make

app: $(APP_SRCS) $(APP_HEAD)
	$(CC) $(CFLAGS) -o eq_solver $(APP_SRCS)

test: app gtest-build $(TEST_SRCS) $(APP_SRCS) $(APP_HEAD)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o eq_solver_tests $(TEST_SRCS) $(APP_SRCS) -I$(GTEST_DIR)/include -L$(GTEST_DIR)/lib -lgtest -lgtest_main -pthread
	./eq_solver_tests

clean:
	rm -f eq_solver eq_solver_tests *.o *.gcda *.gcno *.gcov