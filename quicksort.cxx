#include <iostream>
#include <vector>
#include <iterator>
#include "stack.hxx"

  
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


void quicksort(std::vector<int>& a) { 
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


int main(){

    std::vector<int> vec(
    std::istream_iterator<int>(std::cin),
    std::istream_iterator<int>()
    );


    quicksort(vec); 
  
    for(const auto &i : vec){
        std::cout << i << "\n";
    }

    return 0;
}