#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    int z;
};
    int partition ( Point *a, int l, int r){
    Point pivot = a[r];
    int i = l-1;            //Biến i=l-1-> ban đầu i=-1
    for (int j=l; j<r; j++){       //duyệt mảng
        if(a[j].x<pivot.x ||(a[j].x==pivot.x && a[j].y>pivot.y)||(a[j].x==pivot.x && a[j].y==pivot.y && a[j].z<pivot.z)){
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;
    swap (a[r], a[i]);
    return i;
}
void quickSort( Point *a, int l, int r){
    if(l>=r) return;
    int p = partition(a,l,r);
    quickSort (a, l, p-1);
    quickSort (a, p+1, r);
}

int main()
{
    int n;
    cin>>n;
    Point *a=new Point [n];
    for( int i=0; i<n; i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    quickSort(a,0,n-1);
    for (int i=0; i<n; i++)
		cout << a[i].x << " " << a[i].y<<" "<<a[i].z<< "\n";
    return 0;
}
