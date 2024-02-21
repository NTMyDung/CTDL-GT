#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;
int demkhac (int a[], int n){
    int dem(0);
    for(int i=0; i<n; i++){
        if(a[i]!=a[i+1]) dem++;
    }
    return dem;
}
void In (int a[], int n, int k, int m){
    int dem=0;
    int result=1;
    int trung=k-m;
    cout<<a[0]<<" ";
    for(int i=1; i<n; i++){
        if(a[i]!=a[i-1]){
            cout<<a[i]<<" ";
            result++;
        }
        else {
            if(dem!=trung&& trung>0){
                cout<<a[i]<<" ";
                dem++;
                result++;
            }
        }
        if(result==k) break;
    }
}

int main()
{
    int n, k, dem(0);
    cin>>n;
    cin>>k;
    int a[MAX];
    for (int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);
    In(a,n,k,demkhac(a,n));
    return 0;
}
