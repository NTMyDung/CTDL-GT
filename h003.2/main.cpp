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
    long long result = 0;
    k=0;
    map<long long,long long>::iterator it=count.begin();
    for (auto [x, c] : count) {
        while(it->first<2*x && it!=count.end()){
            k+=it->second;
            it++;
        }
        if(c>1) result += (c * (c - 1) / 2 *(k-c)+ c * (c - 1) * (c - 2) / 6);
    }
    return 0;
}
