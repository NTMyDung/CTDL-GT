#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, k, tmp;
    cin>>n>>k;
    vector<long long> ms;
    for( int i=0; i<n; i++){
        cin>>tmp;
        ms.push_back(tmp);}
    k = k%n;
    rotate(ms.begin(),ms.end()-k,ms.end());
    for(auto i: ms) cout<< i<<" ";
    return 0;
}
