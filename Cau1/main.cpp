/*Câu 1: Cho danh sách A={1,2,3,4,5,6,100000} được lưu trữ trên mảng.
     a) Cho biết thuật toán tốt nhất để tìm giá trị x trong A. Vì sao?
      -> Tìm kiếm nhị phân. Do các phần tử không đồng đều nếu dùng Interpolation Search sẽ phải đi duyệt gần như hết mảng->giống Linear Search.

     b) Trình bày từng bước quá trình tìm giá trị x=6 trong A theo thuật toán đã chọn.
*/

#include <iostream>

using namespace std;

    //Hàm tìm kiếm nhị phân
    int BinarySearch ( int a[], int n, int x){
        n=n-1;
        int l=0, mid;
        while (l<=n){
            mid=(l+n)/2;
            if (x<a[mid]) n=mid-1;
            else if (x>a[mid]) l=mid+1;
            else return mid;
        }
        return -1;
    }
int main()
{
    int a[7]={1,2,3,4,5,6,100000};
    int n= sizeof (a)/sizeof(a[0]);
    cout<<BinarySearch(a,n,6);      //in ra vị trí của 6 trong mảng a[], nếu không có in ra -1.
    return 0;
}
