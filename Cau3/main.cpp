/*Câu 3: Cho cấu trúc điểm trong mặt phẳng như sau:
struct Point {
         float x, y;
};
Viết hàm tìm kiếm điểm q(xq,yq) trong danh sách các điểm A (A được lưu trữ trên mảng) sao cho khoảng cách giữa q và p(xp,yp) là nhỏ nhất.
Trong đó p là một điểm cho trước (tham số của hàm tìm kiếm). Kết quả trả về là chỉ số của q trong A.
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

    struct Point {
         float x, y;
    };

    void Nhap( Point a[100], int n, Point &p){
        cout<<"Nhap danh sach cac diem: "<<endl;
        for ( int i=0; i < n; i++){
            cout<<"Diem thu "<<i<<":";
             cin>>a[i].x>>a[i].y;
        }
        cout<<"Nhap diem cho truoc: ";
        cin>>p.x>>p.y;
    }

    int calculateDistance ( Point a[100], int n, Point p){
        float distance, minDistance = sqrt (pow(p.x-a[0].x,2)+pow(p.y-a[0].y,2));
        int result = 0;
        for( int i=1; i<n; i++){
            distance = sqrt (pow(p.x-a[i].x,2)+pow(p.y-a[i].y,2));
            if (distance < minDistance){
                minDistance = distance;
                result = i;
            }
        }
        return result;
    }

int main()
{
    int n;
    cout<<"Nhap chieu dai mang: ";
    cin>>n;
    Point a[100], p;
    Nhap (a,n,p);
    cout<<"Chi so cua diem gan diem vua nhap nhat trong mang la: "<<calculateDistance ( a, n, p);
    return 0;
}
