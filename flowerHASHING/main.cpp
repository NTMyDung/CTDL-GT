#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;
	vector<int>re;
	for(auto it=A.begin(); it!=A.end(); it++){
        if(Hash.count(*it)>0){
            Hash.find(*it)->second+=1;
        }
        else Hash.insert(pair<int,int>(*it, 1));
	}
	if(Hash.size()>=K){
        for(auto it=Hash.begin(); it!=Hash.end(); ++it){
            if(K==0) break;
            re.push_back(it->first);
            K--;
        }
	}
	else {
        int du=K-Hash.size();
        for(auto it=Hash.begin(); it!=Hash.end(); ++it){
            re.push_back(it->first);
            it->second--;
            while(it->second>0 && du>0){
                re.push_back(it->first);
                it->second--;
                du--;
            }
        }

	}
	return re;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n >> k;

	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> ans = get_ans(a,k);

	for (const int& x: ans) cout << x << ' ';
	return 0;
}
