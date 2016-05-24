#include <iostream>
#include <cstdlib>
using namespace std;
/* Comparison function. Receives two generic (void) pointers. */
int compare (const void * a, const void * b)
{
  const double *da = (const double *) a;
  const double *db = (const double *) b;

  return (*da > *db) - (*da < *db);
  }
int main(){

    int n = rand()% 5000000;
    double arr[n], b[n];
    for (int i=0; i<n; i++)
    {
        arr[i] = (double)rand();
        b[i] = arr[i];
    }
qsort(arr,n, sizeof(double), compare);
 for (int  i=0;i<n;i++){
     cout<<arr[i]<<"\n";
 }
     return 0;
 }
