#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Check(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first)
		return a.second > b.second;
	else
		return a.first < b.first;
}
int main() {
	int n; cin >> n;
	vector<pair<int, int>>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), Check);
	for (int i = 0; i < n; i++)
		cout << a[i].first << " " << a[i].second << "\n";
}
