/* Câu 2: Viết hàm tìm kiếm phần tử x trên mảng A chứa n số nguyên.
Biết A đang có thứ tự > (giảm dần) và chưa biết phân bố giá trị của các phần tử trong A.
*/

#include <iostream>

using namespace std;

    //Hàm tìm kiếm nhị phân khi mảng a là mảng giảm dần
    int BinarySearch ( int a[], int n, int x){
        n=n-1;
        int l=0, mid;
        while (l<=n){
            mid=(l+n)/2;
            if (x<a[mid]) l=mid+1;
            else if (x>a[mid]) n=mid-1;
            else return mid;
        }
        return -1;
    }
int main()
{
    int a[100],n,x;
    cout<<"Nhap so phan tu mang: ";
    cin>>n;
    cout<<"Nhap mang giam dan: "<<endl;
    for ( int i=0; i<n; i++){
        cout<<"a["<<i<<"]:";
        cin>>a[i];
    }
    cout<<"Nhap so can tim vi tri trong mang: ";
    cin>>x;
    cout<< BinarySearch ( a,n,x);
    return 0;
}
