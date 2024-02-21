#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    long long tong;
    cin>>n>>m;
    vector<vector<int>> a;
    for(int i=0; i<n; i++){
            vector<int> hang={};
        for( int j=0; j<m; j++){
            int tmp;
            cin>>tmp;
            hang.push_back(tmp);
        }
        a.push_back(hang);
    }
        long long minn = a[0][0]+a[1][0]+a[2][0]+a[0][1]+a[1][1]+a[2][1]+a[0][2]+a[1][2]+a[2][2];
        for(int i=0; i<n-2; i++){
            for( int j=0; j<(m-2); j++){
                tong = a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
                if (tong < minn) minn = tong;
            }
        }
    cout<<minn;

    return 0;
}
