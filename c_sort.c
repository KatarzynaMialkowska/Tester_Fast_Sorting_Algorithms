#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}
int main(){
    int t, n=0;
    int a[100000];
    while(scanf("%d\n" ,&t)==1){
        a[n] = t;
        //printf("%d ",t);
        n++;
    }
    

    qsort(a, n, sizeof(int), compare);

    for(int i=0; i<n; i++)
    printf("%d\n", a[i]);


    return 0;
}