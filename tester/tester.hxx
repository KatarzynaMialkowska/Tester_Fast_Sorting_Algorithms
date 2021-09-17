#ifndef T_H
#define T_H

#include "heapsort.hxx"
#include "stack.hxx"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <ctime>
#include <random>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <fstream>
#include <cstdio>
#include <stdlib.h> 
#include <stdio.h>



// void count(){
//     static int heap_comparisons = 0;
//     static int heap_swap = 0;
// }


// heapsort
void Heapsort(std::vector<int> v){
    Heap vec;

    vec.heapsort(v); 
}

// quicksort
void swap(int &a, int &b) { 
    int temp = a; 
    a = b; 
    b = temp; 
} 

int partition(std::vector<int> &a, const int &l, const int &r) {
	int v = a[r];
	int i = l;  
	for (int j = l; j < r; ++j)
	{
		if (a[j] < v)
		{
			swap(a[j],a[i]);
			i++;
		}
	}
	swap(a[i], a[r]);
	return i;
}

void quicksort(std::vector<int> a) { 
    int j, l, r;
    Stack<int,100>S;
    S.push(0);
    S.push(a.size()-1);
    do{
        r = S.pop();
        l = S.pop();
        while(l<r){
            j = partition(a,l,r);
             
            if((j - l) <= (r - j)){
                S.push(j+1);
                S.push(r);
                r = j - 1;
            }else{
                S.push(l);
                S.push(j-1);
                l = j + 1;
            }
        }

    }while(!S.empty()); 
} 

// mergesort
int min(const int &a, const int &b) {
     return (a < b) ? a : b;
}

void merge(std::vector<int> &a, const int &l, const int &m, const int &r) {
    int i = 0, j = 0, k = l;
    int nL = (m - l) + 1;
    int nR =  r - m;

    std::vector<int> L(a.begin()+(l), a.begin()+(l+nL));
    std::vector<int> R(a.begin()+(m+1), a.begin()+((m+1+nR)));

    while (i < nL && j < nR){
        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        ++k;
    }

    for (; i < nL; i++){
        a[k++] = L[i];
    }
    for (; j < nR; j++){
        a[k++] = R[j];
    }
}

void mergesort(std::vector<int> a) {

   for (int i = 1; i < a.size(); i *= 2){
  
       for (int l = 0; l < a.size() - 1; l += 2*i){

            int mid = min((l + i) - 1, a.size() - 1);
            int r = min(l + (2 * i) - 1, a.size() - 1);
            merge(a, l, mid, r);
       }
   }
}

// c_sort qsort from c
int compare (const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}

void c_sort(std::vector<int> v){
    int a[1000000], n = 0;

    for(const auto &i : v){
        a[n] = i;
        n++;
    }
    qsort(a, n, sizeof(int), compare);
}

//std::sort
void std_sort(std::vector<int> v){

    std::sort (v.begin(), v.end()); 

}


void generator(std::vector<int>& v, const int& n, const int&& max){

    std::uniform_int_distribution<int> dist1 ( 0, max );
    std::mt19937 gen ( time ( NULL ) );
    
    for( int i = 0; i < n; i++ )
    {
        v.push_back(dist1(gen));
    }

}




#endif