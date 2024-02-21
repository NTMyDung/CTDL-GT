#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<int> a(s.length());
    long tong(0);
    int n=0;
    for (int i=0; i<s.length(); i++){
        a[i] = (int)s[i]-48;
        tong+=a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    if(tong%3==1){
        for( int count =1; count<=2; count++){
            int dem=0;
            for (int i=a.size()-1; i>=0; i--){
                if(count==1){
                    if(a[i]==1||a[i]==4||a[i]==7){
                        a.erase(a.begin()+i);
                        dem++;
                        break;
                    }
                }
                else if(count==2){
                    if(a[i]%3==2){
                        a.erase(a.begin()+i);
                        dem++;
                    }
                }
            }
        if(dem==count) break;
        }
    }
    if(tong%3==2){
        for( int count =1; count<=2; count++){
            int dem=0;
            for (int i=a.size()-1; i>=0; i--){
                if(dem==count) break;
                if(count==1){
                    if(a[i]==2||a[i]==5||a[i]==8){
                        a.erase(a.begin()+i);
                        dem++;
                        break;
                    }
                }
                else if(count==2){
                    if(a[i]%3==1){
                        a.erase(a.begin()+i);
                        dem++;
                    }
                }
            }
        if(dem==count) break;
        }
    }
     for (int i=0; i<a.size(); i++){
        cout<<a[i];
    }

    return 0;
}
