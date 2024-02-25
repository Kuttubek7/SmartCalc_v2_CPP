CFLAGS := -Wall -Wextra -Werror -std=c++17 -I ./include/
OS := $(shell uname -s)
TESTS_SOURCE_FILES := ./sources/tests/ModelTest.cc ./sources/CalcModel.cc
CC := g++

ifeq ($(OS), Darwin)
	TEST_FLAGS = -lgtest_main -lgtest
else
	TEST_FLAGS = -lgtest_main -lgtest -lgmock
endif

all: install
	./bin/SmartCalc

install: clean uninstall
	mkdir -p "build"
	cd build; cmake ..; make;
	mkdir -p "bin"
	mv build/SmartCalc bin/

uninstall:
	rm -rf bin
	rm -rf build

ModelTest: clean build
	./build/test

build:
	mkdir "build"
	${CC} ${CFLAGS} -o ./build/test ${TESTS_SOURCE_FILES} ${TEST_FLAGS}

clean:
	rm -rf ./build
	rm -rf *.gcno

gcov_report: clean
	mkdir "build"
	g++ $(CFLAGS) --coverage ${TESTS_SOURCE_FILES} -o ./build/test $(TEST_FLAGS)
	./build/test
	gcovr -r . --html --html-details  --exclude 'sources/tests/*' -o build/coverage_report.html
	open build/coverage_report.html

dvi:
	mkdir -p "dvi"
	doxygen Doxyfile
	open html/index.html
	cd dvi; make;

dist:
	mkdir -p "SmartCalc_v2_0"
	cp -r ./*Make* ./Doxyfile ./include ./sources SmartCalc_v2_0/
	tar -zcf SmartCalc_v2_0.tar.gz SmartCalc_v2_0
	rm -rf SmartCalc_v2_0

linter:
	cp ../materials/linters/.clang-format sources/.
	cp ../materials/linters/.clang-format sources/tests/.
	cp ../materials/linters/.clang-format include/
	clang-format -i sources/*.cc
	clang-format -i include/*.h
	clang-format -i sources/tests/*.*
	rm -rf sources/.clang-format
	rm -rf sources/tests/.clang-format
	rm -rf include/.clang-format

vg: clean build
	 leaks --atExit -- ./build/test
