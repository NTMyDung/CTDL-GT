#include <iostream>
#include <map>
#include <vector>
using namespace std;
void findTKMK(int n, int q){
    map<string,vector<string>>Hash;
    string tk, mk;
    for( int i=0; i<n; i++){
        cin.ignore();
        cin>>tk>>mk;
        if(Hash.count(tk)==0){
            vector<string> dayMK(1,mk);
            Hash.insert({tk,dayMK});
        }
        else{
            Hash.find(tk)->second.push_back(mk);
        }
    }
    for (int i=0; i<q; i++){
        cin>>tk;
        if(Hash.count(tk)==0){
            cout<<"Chua Dang Ky!"<<endl;

        }
        else{
            for(auto it=Hash.find(tk)->second.begin();it!=Hash.find(tk)->second.end(); it++)
                cout<<*it<< " ";
            cout<<endl;
        }
    }
}

int main()
{
    int n, q;
    cin>>n>>q;
    findTKMK(n,q);

    return 0;
}
