#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void BFS( int **p, int maxx, int x, int y, int a[], int seen[], queue<int>q){
    while(!q.empty()){
        x=q.front();
        q.pop();
        seen[x]=1;
        for( int i=1; i<=maxx; i++){
            if(p[x][i]==1 && seen[i]==0){
                a[i]=x;
                seen[i]=1;
                if(i==y) return;
                q.push(i);
            }
        }
    }
}
void Tim(int **p, int x, int y, int maxx){
    int seen[27]={0};
    queue<int>q;
    int a[27]={0};
    q.push(x);
    BFS(p,maxx, x, y, a, seen, q);
    stack <int>s;
    s.push(y);
    while(y!=x){
        if(a[y]!=0) y=a[y];
        else {
            cout<< "no_path";
            return;
        }
        s.push(y);
    }
    if(s.top()==x){
        while(!s.empty()){
            cout<<(char)(s.top()+64)<< " ";
            s.pop();
        }
    }
    else cout<< "no_path";
}

int main()
{
    int **p;
    p=new int *[27];
    int n, e, m;
    cin>>n>>e;
    char x, y;
    int h,u;
    int maxx=1;
    for(int i=0; i<n; i++){
        cin>>x;
        h=x-64;
        maxx=max(maxx,h);
        p[h]=new int[27];
        for( int j=1; j<27; j++)
            p[h][j]=0;
    }
    for( int i=0; i<e; i++){
        cin>>x>>y;
        h=x-64; u=y-64;
        p[h][u]=1;
    }
    cin>>m;
    for( int i=0; i<m; i++){
        cin>>x>>y;
        h=x-64; u=y-64;
        if(h==u) cout<<(char)(h+64);
            else Tim(p,h,u, maxx);
        cout<<endl;
    }
    return 0;
}
