#include"heapsort.hxx"

int main()
{
    Heap v;
//    std::vector<int> vec{2,24,44,1,5,6,7,8};
    std::vector<int> vec(
    std::istream_iterator<int>(std::cin),
    std::istream_iterator<int>()
    );


    v.heapsort(vec); 
  
    for(const auto &i : vec){
        std::cout << i << "\n";
    }
    return 0;
}