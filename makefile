FILES := 				 \
	.travis.yml				 \
	integer-tests/ll9338-RunInteger.out	 \
	integer-tests/ll9338-TestInteger.c++ \
	integer-tests/ll9338-TestInteger.out \
	Integer.h				 \
	Integer.log				 \
	html				 \
	RunInteger.c++			 \
	RunInteger.out			 \
	TestInteger.c++			 \
	TestInteger.out			 \

ifeq ($(CXX), clang++)
	CXXVER    := --version 2>&1 | grep clang
	GTESTVER  := dpkg -l libgtest-dev | grep libgtest
	GCOV      := gcov-4.6
	GCOVFLAGS := --coverage
	GCOVVER   := -v | grep gcov
	BOOST     := /usr/include/boost
	LDFLAGS   := -lgtest -lgtest_main -pthread
	VALGRIND  := valgrind
else
	CXX       := g++-4.8
	CXXVER    := --version 2>&1 | grep g++
	GTESTVER  := dpkg -l libgtest-dev | grep libgtest
	GCOV      := gcov-4.8
	GCOVFLAGS := -fprofile-arcs -ftest-coverage
	GCOVVER   := -v | grep gcov
	BOOST     := /usr/include/boost
	LDFLAGS   := -lgtest -lgtest_main -pthread
	VALGRIND  := valgrind
endif

CXXFLAGS := -pedantic -std=c++11 -Wall
LDFLAGS  := -lgtest -lgtest_main -pthread
VALGRIND := valgrind

check:
	@for i in $(FILES);                                         \
	do                                                          \
		[ -e $$i ] && echo "$$i found" || echo "$$i NOT FOUND"; \
	done

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunInteger
	rm -f RunInteger.out
	rm -f TestInteger
	rm -f TestInteger.out
config: 
	git config -l

test: RunInteger.out TestInteger.out

versions:
	uname -a
	@echo
	printenv
	@echo
	which $(CXX)
	@echo hi
	$(CXX) $(CXXVER)
	@echo hi
	$(GTESTVER)
	@echo
	which $(GCOV)
	@echo
	$(GCOV) $(GCOVVER)
	@echo
	grep "#define BOOST_VERSION " $(BOOST)/version.hpp
ifdef VALGRIND
	@echo
	which $(VALGRIND)
	@echo
	$(VALGRIND) --version
endif
	@echo
	which doxygen
	@echo
	doxygen --version

integer-tests:
	git clone https://github.com/cs378-summer-2015/integer-tests.git

html: Doxyfile Integer.h RunInteger.c++ TestInteger.c++
	doxygen Doxyfile


Integer.log:
	git log > Integer.log


Doxyfile: 
	doxygen -g

RunInteger: Integer.h RunInteger.c++
	$(CXX) $(CXXFLAGS) RunInteger.c++ -o RunInteger

RunInteger.out: RunInteger
	./RunInteger > RunInteger.out
	cat RunInteger.out

TestInteger.out: TestInteger
	$(VALGRIND) ./TestInteger  >  TestInteger.out 2>&1
	$(GCOV) -b TestInteger.c++ >> TestInteger.out
	cat TestInteger.out

TestInteger: Integer.h RunInteger.c++ TestInteger.c++
	$(CXX) $(COVFLAGS) $(CXXFLAGS) Integer.h TestInteger.c++ -o TestInteger $(LDFLAGS)