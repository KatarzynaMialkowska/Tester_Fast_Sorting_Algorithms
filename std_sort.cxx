#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{

    std::vector<int> vec(
    std::istream_iterator<int>(std::cin),
    std::istream_iterator<int>()
    );


    std::sort(vec.begin(), vec.end()); 
  
    for(const auto &i : vec){
        std::cout << i << "\n";
    }
    return 0;
}