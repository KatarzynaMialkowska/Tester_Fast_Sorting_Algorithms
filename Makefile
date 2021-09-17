
.SUFFIXES: .cxx .o .x .hxx .c .cpp
NAME1 = c_sort
NAME2 = heapsort
NAME3 = mergesort
NAME4 = quicksort
NAME5 = genReverse
NAME6 = genSorted
NAME7 = genSortedFirst
NAME8 = genSortedLast
NAME9 = generator
NAME10 = std_sort
NAME11 = tester/tester

C1 = $(NAME1).c

CXX2 = $(NAME2).cxx
CXX3 = $(NAME3).cxx
CXX4 = $(NAME4).cxx

CPP5 = $(NAME5).cpp
CPP6 = $(NAME6).cpp
CPP7 = $(NAME7).cpp
CPP8 = $(NAME8).cpp

CXX9 = $(NAME9).cxx
CXX10 = $(NAME10).cxx
CXX11 = $(NAME11).cxx

EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x
EXEC5 = $(NAME5).x
EXEC6 = $(NAME6).x
EXEC7 = $(NAME7).x
EXEC8 = $(NAME8).x
EXEC9 = $(NAME9).x
EXEC10 = $(NAME10).x
EXEC11 = $(NAME11).x

CO=g++
CC=gcc
FLAGS= -std=c++11
CFLAGS= -O3 -march=native

.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5) $(EXEC6) $(EXEC7) $(EXEC8) $(EXEC9) $(EXEC10)


$(EXEC1):
	$(CC) -o $@ $(C1) $(CFLAGS)

$(EXEC2): 
	$(CO) -o $@ $(CXX2) $(FLAGS)

$(EXEC3):
	$(CO) -o $@ $(CXX3) $(FLAGS) 

$(EXEC4):
	$(CO) -o $@ $(CXX4) $(FLAGS) 

$(EXEC5):
	$(CO) -o $@ $(CPP5) $(FLAGS) 
	
$(EXEC6):
	$(CO) -o $@ $(CPP6) $(FLAGS) 

$(EXEC7):
	$(CO) -o $@ $(CPP7) $(FLAGS) 

$(EXEC8):
	$(CO) -o $@ $(CPP8) $(FLAGS) 

$(EXEC9):
	$(CO) -o $@ $(CXX9) $(FLAGS) 

$(EXEC10):
	$(CO) -o $@ $(CXX10) $(CFLAGS) $(FLAGS)

$(EXEC11):
	$(CO) -o $@ $(CXX11) $(FLAGS) 
##TESTER##

#tester is a program that compares all sortings in time,#
#and generates visualizations in the form of a chart in pdf.#

ctest: $(EXEC11)

.PHONY: test
test: ctest
	@echo "\n\t*START TEST*\n"
	@./$(EXEC11)




.PHONY: clean
clean:                                                     
	rm -f *.o  *~ *.a *.so *.pdf *.dat *.x *.txt core core* a.out; rm -rf ${LIB_DIR}
	rm -f tester/*.o tester/*.dat tester/*.pdf tester/*.x tester/*.txt