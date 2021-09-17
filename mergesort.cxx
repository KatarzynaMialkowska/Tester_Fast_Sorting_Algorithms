#include <iostream>
#include <vector>
#include <iterator>

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

void mergesort(std::vector<int> &a) {
   for (int i = 1; i < a.size(); i *= 2){
  
       for (int l = 0; l < a.size() - 1; l += 2*i){

            int mid = min((l + i) - 1, a.size() - 1);
            int r = min(l + (2 * i) - 1, a.size() - 1);
            merge(a, l, mid, r);
       }
   }
}

int main()
{
    std::vector<int> vec(
    std::istream_iterator<int>(std::cin),
    std::istream_iterator<int>()
    );


    mergesort(vec); 
  
    for(const auto &i : vec){
        std::cout << i << "\n";
    }
    return 0;
}