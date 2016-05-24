#include <iostream>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
using namespace std;
void QuickSort(double arr[],int first,int last)
 {
     int i=first+1,j=last,temp;
     if(i>j)
     return;
     while(i<=j)
     {
              while(arr[i]<arr[first])
              {
			  i++;
			  }
              while(arr[j]>arr[first])
              {
                               j--;
              }
              if(i<=j)
              {
                  temp=arr[i];
                  arr[i]=arr[j];
                  arr[j]=temp;
              }
      }

       temp=arr[first];
       arr[first]=arr[j];
       arr[j]=temp;

       QuickSort(arr,first,j-1);
       QuickSort(arr,j+1,last);

}
int compare (const void * a, const void * b)
{
  const double *da = (const double *) a;
  const double *db = (const double *) b;

  return (*da > *db) - (*da < *db);
  }
int main(){
int s = rand()% 5000000;
    srand (time(NULL));
    int n = rand()% 5000000;

    double arr[n], b[n];
    for (int i=0; i<n; i++)
    {
        arr[i] = (double)rand();

        b[i] = arr[i];
    }
              timeval tim;
             gettimeofday(&tim, NULL);
             double t1=tim.tv_sec+(tim.tv_usec/1000000.0);
QuickSort(arr,0,n-1);
       gettimeofday(&tim, NULL);
             double t2=tim.tv_sec+(tim.tv_usec/1000000.0);
             cout << "seconds elapsed using quicksort: " << t2-t1;
 for (int  i=0;i<n;i++){
     cout<<arr[i]<<"\n";
 }
 for (int i=0; i<n; i++)
    {
        arr[i] = b[i];
    }
    timeval timed;
                 gettimeofday(&timed, NULL);
             double s1=timed.tv_sec+(timed.tv_usec/1000000.0);
qsort(arr,n, sizeof(double), compare);
       gettimeofday(&tim, NULL);
             double s2=timed.tv_sec+(timed.tv_usec/1000000.0);
             cout << "seconds elapsed using qsort: " << s2-s1;
 for (int  i=0;i<n;i++){
     cout<<arr[i]<<"\n";
 }
     return 0;
 }
