#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>
#include <sstream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <vector>
#include <iterator>

int compare (const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}
int main(int argc, char *argv[])
{
    int n, max;
    if(argc==3){
        for (int i = 1; i <= 2; i++) {
            if (!isdigit(*argv[i])) {
                 std::cout << "ARGUMENTY MUSZA BYC LICZBA\n";
                exit(EXIT_FAILURE);
            }
        }

       std::istringstream iss1( argv[1] );
       if (iss1 >> n){}
        std::istringstream iss2( argv[2] );
       if (iss2 >> max){}

    }else{

        std::cout << "ZLA LICZBA ARGUMENTOW\nliczba losowan<n> maksymalny zakres<max>\n";
        exit (EXIT_FAILURE);

    }
    std::uniform_int_distribution<int> dist1 ( 0, max ); 
    std::mt19937 gen ( time ( NULL ) ); // pseudo-random generator Mersenne Twister 32bit
    
    std::vector<int>v;
    for( int i = 0; i < n; i++ )
    {
         v.push_back(dist1(gen));
    }
    qsort(&v[1], v.size()-1, sizeof(int), compare);

    for( int i = 0; i < n; i++ )
    {
         std::cout << v[i] << "\n";
    }
 
    return 0;
} 