/*#include <iostream>
using std::cin;
using std::cout;
using std::endl;
*/
    void merge (int *a,int n, int *b, int m, int *c){
        int i=0;
        int j=0;
        int z=0;
        while(i!=n&&j!=m){
            if(a[i]<=b[j]){
                c[z]=a[i];
                z++; i++;
            }
            else {
                c[z]=b[j];
                z++; j++;
            }
        }
        while (i!=n){
            c[z]=a[i];
            z++; i++;
        }
        while (j!=m){
            c[z]=b[j];
            z++; j++;
        }
    }
/*
int main()
{
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n,m;
    int t;
    cin>>t;
    while( cin>>n>>m||t>0){
        t--;
        int *a =new int[n], *b =new int[m], *c=new int [m+n];
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<m; i++) cin>>b[i];
        merge(a,n,b,m,c);
        int nc=n+m;
        for(int i=0; i<nc; i++){
            cout<<c[i]<<" ";
        }
        delete c;
        cout<<endl;
    }
    return 0;
}
