#include <iostream>
#include <cstdlib>
using namespace std;
/* Comparison function. Receives two generic (void) pointers. */
int compare (const void * a, const void * b)
{
    int ret;
    int x = *(int*)a;
    int y = *(int*)b;

    /* Avoid return x - y, which can cause undefined behaviour
       because of signed integer overflow. */
    if (x == y)
        ret = 0;
    else if (x < y)
        ret = -1;
    else
        ret = 1;

    return ret;

}
int main(){

    int n = rand()% 5000000;
    double arr[n];
    for (int i=0; i<n; i++)
    {
        arr[i] = (double)rand();
    }
qsort(arr,n, sizeof(double), compare);
 for (int  i=0;i<n;i++){
     cout<<arr[i]<<"\n";
 }
     return 0;
 }
