#include <iostream>

using namespace std;

// Khai báo cấu trúc node
typedef struct node{
    int data;
    node *pNext;
}Node;

// Khai báo cấu trúc list
typedef struct list{
    Node *pHead;
    Node *pTail;
}List;

// Khởi tạo node
Node * createNode(int x){
    Node *p = new Node;
    if (p == NULL) return NULL;
    p ->data = x;
    p -> pNext = NULL;
    return p;
}

// Khởi tạo Stack
void initStack(List &s){
    s.pHead = s.pTail = NULL;
}

bool isEmpty(List s){
    return s.pHead == NULL;
}

void push(List &s, Node *Tam){
    if (isEmpty(s)){
    	s.pHead = Tam;
		s.pTail = Tam;
	}else{
        Tam -> pNext = s.pHead;
		s.pHead = Tam;
	}
}

void pop(List &s){
    Node *p;
    if(!isEmpty(s)){
        p = s.pHead;
        s.pHead = s.pHead -> pNext;
        delete p;
        if(s.pHead == NULL)
            s.pTail = NULL;
    }else{
        cout << "Stack rong!";
    }
}

int top(List &s){
    if(!isEmpty(s))
        return s.pHead -> data;
    return -1;
}

void ChuyenNhiPhan (List &l, int x){
    Node *p=new Node;;
    while(x!=0){
        p = createNode(x%2);
        push(l, p);
        x/=2;
    }
    while(!isEmpty(l)){
        cout<<top(l);
        pop(l);
    }
    cout<<endl;
}

int main(){

    List s, l;
    initStack(s); initStack(l);
    Node *p;
    int value;
    int x;
    int select;

    cout << "************************************\n";
    cout << "1. Them phan tu vao Stack (push)\n";
    cout << "2. Loai phan tu khi Stack (pop)\n";
    cout << "3. Lay phan tu tren cung Stack (top)\n";
    cout << "4. Chuyen doi co so nhi phan\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "************************************\n";

    do{
        cout << "Chon chuc nang muon xu ly: "; cin >> select;
        switch (select){
        case 0:
            cout << "Tam biet!\n";
            break;
        case 1:
            cout << "Nhap gia tri phan tu them vao Stack: "; cin >> value;
            p = createNode(value);
            push(s, p);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            value = top(s);
            if(value == -1)
                cout << "Stack rong!\n";
            else
                cout << "Phan tu tren cung cua Stack la: " << value << "\n";
            break;
        case 4:
            cout<<"Nhap so can chuyen doi sang so nhi phan: ";
            cin>>x;
            ChuyenNhiPhan(l, x);
            break;
        default:
            break;
        }
    }while(select);

    return 0;
}
