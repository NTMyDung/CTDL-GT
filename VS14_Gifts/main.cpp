#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000
using namespace std;

int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> a;
    for( int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        if(tmp<x) a.push_back(tmp);
    }
    sort( a.begin(), a.end());
    int result = -1, tong;
    for ( int i=a.size(); i>0; i--){
        for( int j=i-1; j>=0; j--){
            tong = a[i]+a[j];
            if(tong > result && tong<=x) {
                result = tong;
                break;
            }
        }
    }
    cout<<result;
    return 0;
}
