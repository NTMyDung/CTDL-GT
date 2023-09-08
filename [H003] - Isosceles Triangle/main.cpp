#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    long long n;
    long long k;
    cin >> n;
    map<long long, long long> count;
    for (long long i=0; i<n; i++){
        cin>>k;
        count[k]++;
    }
    k=(--count.end())->first;
    long long result = 0;
    for (auto [x, c] : count) {
        if(c>1)
        {
            long long dem=0;
            if(k >= 2*x){

                if(k/2 >= 2*x){
                    dem=n;
                    for( auto it=count.begin(); it->first < 2*x; it++) dem-=it->second;
                    }
                else
                    for(auto it=count.lower_bound(2*x); it!=count.end(); it++) dem+=it->second;
            }
            result += (c * (c - 1) / 2 *(n-c-dem)+ c * (c - 1) * (c - 2) / 6);
        }
    }
    cout << result << endl;
    return 0;
}
