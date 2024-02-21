#include <iostream>

using namespace std;

//Định nghĩa cấu trúc node
typedef struct node{
    int data;
    struct node *pNext;
}Node;
//Định nghĩa cấu trúc list
typedef struct list {
    Node *pHead;
    Node *pTail;
}List;
//Tạo node
Node *createNode (int x){
    Node *p;
    p=new Node;
    if (p==NULL) return NULL;
    p->data=x;
    p->pNext=NULL;
    return p;
}
//Khởi tạo list
void initList (List &l){
    l.pHead = l.pTail = NULL;
}
//Thêm node vào đầu danh sách
void addHead (List &l, Node *p){
    if(l.pHead==NULL){       //List đang rỗng
        l.pHead=p;
        l.pTail=l.pHead;
    }
    else{
        p->pNext=l.pHead;
        l.pHead = p;
    }
}

//Thêm node vào cuối danh sách
void addTail (List &l, Node *p){
    if(l.pHead==NULL){       //List đang rỗng
        l.pHead=p;
        l.pTail=l.pHead;
    }
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
//Thêm node p vào sau node q cho trc
int  addNodeAfterQ (List &l, Node *p, Node *q){
    if(q==NULL) return 0;
    p->pNext =q->pNext;
    q->pNext = p;   //Ngat lien ket khong phai phep gan
    if(q->pNext==NULL)
        l.pTail=p;
    return 1;
}
//Thêm node p vào sau node q có giá trị x
Node *findNodeX(List l, int x){
    Node *p;
    p=l.pHead;
    while (p!=NULL && p->data!=x){
        p=p->pNext;
    }
    return p;
}
int addNodeAfterX (List &l, Node *p, int x){
    Node *q;
    q=findNodeX(l,x);
    if(q!=NULL)
        addNodeAfterQ(l,p,q);
    else return 0;
    return 1;
}
//Xóa node đầu
int removeHead (List &l, int &x){
    Node *p;
    if(l.pHead !=NULL){
        p=l.pHead;
        x=p->data;
        l.pHead=l.pHead->pNext;
        delete p;
        if(l.pHead==NULL) l.pTail=NULL;
        return 1;
    }
    return 0;
}
void addNodeBeforX (List &l, Node *p, int x){
    Node *q, *pr;
    pr=NULL;
    q=l.pHead;
    while(q!=NULL&&q->data!=x){
        pr=q;
        q=q->pNext;
    }
    if(q!=NULL){
        addNodeAfterQ(l,p, pr);
    }
    if(q==l.pHead&&q->data==x){
        addHead(l, p);
    }
}
//Hủy phần tử đứng sau phần tử q trong ds
int removeAfterQ (List &l, Node *q, int &x){
    Node *p;
    if(q!=NULL){
        p=q->pNext;
        if(p!=NULL) {
            if(0==l.pTail) l.pTail=q;
            q->pNext=p->pNext;
            x=p->data;
            delete p;
        }
        return 1;
    }
    return 0;
}
//Xóa phần tử có giá trị x
int removeX (List &l, int x){
    Node *p=l.pHead, *q=NULL;
     while(p!=NULL&&p->data!=x){
        q=p;
        q=q->pNext;
    }
    if(p==NULL) {
        return 0;
    }
    if(q!=NULL) {
        removeAfterQ(l,q,x);
    }
    else removeHead(l,x);
    return 1;
}
//Xóa danh sách ----------------->XÓA TỪ CUỐI????????
void removeList (List &l){
    Node *p;
    while(l.pHead!=NULL){
        p=l.pHead;
        l.pHead=p->pNext;
        delete p;
    }
}

//In danh sách
void printList (List l){
    //Node *p;
    //p=l.pHead;
    /*
    while (p !=NULL){
        cout<<p->data<<" ";
        p=p->Next;
    }
    */
    for(Node *p=l.pHead; p!= NULL; p=p->pNext)
        cout<<p->data<<" ";
    cout<<"\n";
}

int main()
{
    List l;
    initList (l);
    Node *p;
    int x, y;
    cout<<"************************************\n";
    cout<<"1. Them node vao dau ds.\n";
    cout<<"2. Them node vao cuoi ds.\n";
    cout<<"3. In danh sach.\n";
    cout<<"4. Tim node co gia tri x.\n";
    cout<<"5. Them node p vao sau node q co gia tri x.\n";
    cout<<"0. Thoat chuong trinh.\n";
    cout<<"************************************\n";
    int select;
    do{
        cout<<"Chon chuc nang thuc hien: ";
        cin>>select;
        switch (select){
            case 0:
                cout<<"Tam biet!";
                break;
            case 1:
                cout<<"Nhap gia tri cua node can them vao dau: ";
                cin>>x;
                p=createNode(x);
                addHead(l, p);
                break;
            case 2:
                cout<<"Nhap gia tri cua node can them vao cuoi: ";
                cin>>x;
                p=createNode(x);
                addTail(l, p);
                break;
            case 3:
                cout<<"Danh sach lien ket: ";
                printList(l);
                break;
            case 4:
                cout<<"Nhap gia tri node can tim: ";
                cin>>x;
                p= findNodeX (l,x);
                if(p==NULL)
                    cout<<"Khong tim thay node co gia tri "<<x<<endl;
                else
                    cout<<"Tim thay node co gia tri "<<x<<endl;
                break;
            case 5:
                cout<<"Nhap gia tri node q can tim: ";
                cin>>x;
                cout<<"Nhap gia tri node p can them: ";
                cin>>y;
                p=createNode(y);
                if(addNodeAfterX(l,p,x)==1) cout<<"Them thanh cong!\n";
                else cout<<"Khong the them vi khong tim thay node q co gia tri "<<x<<endl;
                break;
            default: break;
        }
    }while(select!=0);
    return 0;
}
