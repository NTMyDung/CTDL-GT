#include <iostream>
#include <vector>

using namespace std;

    void rotate(vector<int>& nums, int k) {
        for ( int i=0; i<= nums.size(); i++){
            nums.insert(nums.begin(), nums.end()-1);
            nums.pop_back(nums.end()-1);
        }
    }

int main()
{
    int n, k;
    vector<int> nums;
    cin>>n>>k;
    for( int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<< rotate(nums,k);
    return 0;
}
