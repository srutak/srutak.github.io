#include <iostream>
using namespace std;
void QuickSort(int arr[],int first,int last)
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
int main(){

    int arr[]={12,43,13,5,8,10,11,9,20,17};
    int n=sizeof(arr)/sizeof(int);
QuickSort(arr,0,n-1);
 for (int  i=0;i<n;i++){
     cout<<arr[i]<<"  ";
 }
     return 0;
 }
