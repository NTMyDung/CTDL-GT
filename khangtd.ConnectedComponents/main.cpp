#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
void BFS( int **p, int x, int y, int a[] ,int seen[]){
    queue<int>q;
    q.push(x);
    seen[x]=1;
    while(!q.empty()){
        int v=q.front(); q.pop();
        for( int i=0; i<27; i++){
            if(p[x][i]==1 && seen[i]==0){
                q.push(i);
                a[i]=x;
                seen[i]=1;
                if(i==y) break;
            }
        }
        if(a[y]!=0) break;
    }
}
void Tim(int **p, int x, int y){
    int seen[27];
    int a[27];
    BFS(p, x, y, a, seen);
    if(a[y]==0){
        cout<< "no_path";
        return;
    }
    vector<int>v;
    while(y!=x){
        v.push_back(y);
        if(a[y]!=0) y=a[y];
        else {
            cout<< "no_path";
            return;
        }
    }
    v.push_back(x);
    reverse(v.begin(), v.end());
    for( int i:v){
        cout<<(char)(i+64)<< " ";
    }
}

int main()
{
    int **p;
    p=new int *[27];
    int n, e, m;
    cin>>n;
    cin>>e;
    char x, y;
    int h,u;
    for(int i=0; i<n; i++){
        cin>>x;
        h=x-64;
        p[h]=new int[27];
        for( int j=0; j<27; j++)
            p[h][j]=0;
    }
    for( int i=0; i<e; i++){
        cin>>x>>y;
        h=x-64;
        u=y-64;
        p[h][u]=1;
    }
    cin>>m;
    for( int i=0; i<m; i++){
        cin>>x>>y;
        h=x-64; u=y-64;
        if(h==u) cout<<x;
        else Tim(p,h,u);
        cout<<endl;
    }
    return 0;
}
