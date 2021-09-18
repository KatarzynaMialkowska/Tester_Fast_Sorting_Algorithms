# Tester_Fast_Sorting_Algorithms

Author: Katarzyna Miałkowska
## Contents ##

1) generator.cxx
-Generate random output, specifying in the in argument:
[data amount] [maximum range]

2) genSorted.cpp

-Generates a random ascending sequence, specifying in the in argument:
[data amount] [maximum range]

3) genReverse.cpp
- Generates a random descending sequence, specifying in the in argument:
[data amount] [maximum range]

4) genSortedFirst.cpp
- Generates a random sequence increasing with a random element at the beginning, specifying in the in argument:
[data amount] [maximum range]

5) genSortedLast.cpp
- Generates a random sequence increasing with a random element at the end, specifying in the in argument:
[data amount] [maximum range]

6) heapsort.cxx
 - Program includes heap implementations and heapsort

7) quicksort.cxx
 - Program includes non-recursive sort implementations quicksort

9) mergesort.cxx
 - Program includes non-recursive sort implementations mergesort 

10) c_sort.c
 - The program includes implementations of qsort from the standard C library

11) std_sort.cxx
 - The program includes sort implementations of std::sort from the standard C ++ library

12) Tester
- Includes a tester  

## Makefile ##

- To compile all programs,, execute: 
make all
- To clean the contents of unnecessary files, execute: 
make clean
- To run the tester, execute:
 make test

## Tester ##

The tester is located in the "tester" folder.
The tester program compares all of the above sort implementations in time and generates a chart.

1) tester.cxx - tester implementation that calls all sort implementations for n random operations:
n = 10,000, 20,000, 80,000, 160,000.
 Displays the execution time for each sort, then generates a graph showing visually, the time of sorting for n data. The chart will be in the graphs.pdf file

2) tester.hxx - contains all sort implementations and generator.

3) gnuplot.hxx - the class needed to generate a chart using the Gnuplot program.
