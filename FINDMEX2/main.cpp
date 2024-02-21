#include <iostream>

using namespace std;
int partition ( int a[], int l, int r){
    int pivot = a[r];
    int i = l-1;
    for ( int j=l; j<r; j++){
        if(a[j]<= pivot){
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;
    swap (a[r], a[i]);
    return i;
}
void quickSort( int a[], int l, int r){
    if(l>=r) return;
    int p = partition(a,l,r);
    quickSort (a, l, p-1);
    quickSort (a, p+1, r);
}


int main()
{
    int n, x;
    cin>>n;
    int *a=new int[n];
    int re=0;
    for(int i=0; i<n; i++){
        cin>>x;
        a[i]=x;
    }
    quickSort(a,0,n-1);
    for( int j=0; j<n; j++){
        if(a[j]==re) re++;
        if(a[j]>re) break;
    }
    cout<<re;

    return 0;
}
