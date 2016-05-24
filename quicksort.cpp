#include <iostream>
using namespace std;
void exch(int a[],int i,int j){
    int s=a[i];
    a[i]=a[j];
    a[j]=s;

}

void quick(int a[],int l,int h){
    if (h<=l) return ;
    int j=partition(a,l,h);
    quick(a,l,j-1);
    quick(a,j+1,h);
    }
int partition(int a[],int l,int h){
    int i=l-1;
    int j=h;
    int v=a[h];
    while(true){

        while( a[++i]<v);

        while(a[--j]>v) if (j==i)  break;

            if (i>=j) break;

        exch(a,i,j);

    }

    exch(a,i,h);
    return i;



}
int main(){

    int a[]={12,43,13,5,8,10,11,9,20,17};
    int n=sizeof(a)/sizeof(int);
quick(a,0,n-1);
 for (int  i=0;i<n;i++){
     cout<<a[i]<<"  ";
 }
     return 0;
 }
