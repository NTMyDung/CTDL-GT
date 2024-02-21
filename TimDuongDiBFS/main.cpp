#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void BFS(vector<vector<char>>v ,char p[], int n, char x, char kt, int seen[], queue<char>q){
    seen[x]=1;
    vector <char> xuly;
    for(auto it=v.begin(); it!=v.end();it++){
        if( it->front()==x) {
            xuly=*it;
            break;
        }
    }
    for( auto it=++xuly.begin(); it!=xuly.end(); it++){
        if(seen[*it]==0){
            p[*it]=x;
            if(*it==kt) return;
            seen[*it]=1;
            q.push(*it);
        }
    }
    if(!q.empty()){
        x=q.front();
        q.pop();
        BFS(v,p,n,x,kt,seen,q);
    }
}
void Tim(vector<vector<char>>v ,char p[],int n, char x, char kt, int seen[], queue<char>q){
    BFS(v,p,n,x,kt,seen,q);
    stack <char>s;
    s.push(kt);
    while(kt!=x){
        if('A'<=p[kt]<='Z') kt=p[kt];
        else {
            cout<< "no_path";
            return;
        }
        s.push(kt);
    }
    while(!s.empty()){
        cout<<s.top()<< " ";
        s.pop();
    }
}

int main()
{

    int n, e, m;
    cin>>n>>e;
    vector<vector<char>>v;
    char x, y;
    vector<char> d;
    vector<char> tmp;
    for(int i=0; i<n; i++){
            cin>>x;
        d.push_back(x);
    }
    for( int i=0; i<e; i++){
        cin>>x>>y;
        if(tmp.empty())tmp.push_back(x);
        else if (x!=tmp.front()){
            tmp.clear();
            tmp.push_back(x);
        }
        else tmp.push_back(y);
    }
    char kt;
    cin>>m;
    for( int i=0; i<m; i++){
        cin>>x>>kt;
        int seen[100]={0};
        char p[100];
        queue<char>q;
        Tim(v,p,n,x,kt,seen,q);
    }
    return 0;
}
