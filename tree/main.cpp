#include <iostream>
using namespace std;

// Khai báo cấu trúc Node
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}Node;
typedef Node *TREE;

// Hàm tạo một Node mới
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Khởi tạo câu
void Init (TREE &t) {
    t=NULL;
}

// Hàm thêm một Node vào cây
Node* insertNode(TREE &t, int data) {
    if (t == NULL) {
        return createNode(data);
    }
    if (data < t->data) {
        t->left = insertNode(t->left, data);
    }
    else if (data > t->data) {
        t->right = insertNode(t->right, data);
    }
    return t;
}

// Hàm duyệt cây theo thứ tự LNR
void LNR(TREE t) {
    if (t != NULL) {
        LNR(t->left);
        cout << t->data << " ";
        LNR(t->right);
    }
}

// Hàm duyệt cây theo thứ tự NLR
void NLR(TREE t) {
    if (t != NULL) {
        cout << t->data << " ";
        NLR(t->left);
        NLR(t->right);
    }
}

// Hàm duyệt cây theo thứ tự LRN
void LRN(TREE t) {
    if (t != NULL) {
        LRN(t->left);
        LRN(t->right);
        cout << t->data << " ";
    }
}

// Hàm tính độ sâu của cây
int depth(TREE t) {
    if (t == NULL) {
        return 0;
    }
    int leftDepth = depth(t->left);
    int rightDepth = depth(t->right);
    return max(leftDepth, rightDepth) + 1;
}

// Hàm tính tổng số node trên cây
int countNodes(TREE t) {
    if (t == NULL) {
        return 0;
    }
    return countNodes(t->left) + countNodes(t->right) + 1;
}

// Hàm tính tổng số node lá trên cây
int countLeaves(TREE t) {
    if (t == NULL) {
        return 0;
    }
    if (t->left == NULL && t->right == NULL) {
        return 1;
    }
    return countLeaves(t->left) + countLeaves(t->right);
}

// Hàm tìm node có giá trị lớn nhất trên cây
Node* findMax(TREE t) {
    if (t == NULL) {
        return NULL;
    }
    if (t->right == NULL) {
        return t;
    }
    return findMax(t->right);
}

// Hàm tìm node có giá trị nhỏ nhất trên cây
Node* findMin(TREE t) {
    if (t == NULL) {
        return NULL;
    }
    if (t->left == NULL) {
        return t;
    }
    return findMin(t->left);
}

// Hàm tính tổng số node có giá trị lớn hơn k
int countNodesGreaterThanK(TREE t, int k) {
    if (t == NULL) {
        return 0;
    }
    if (t->data > k) {
        return countNodesGreaterThanK(t->left, k) + countNodesGreaterThanK(t->right, k) + 1;
    }
    return countNodesGreaterThanK(t->right, k);
}

// Hàm tính tổng số node có giá trị nhỏ hơn k
int countNodesLessThanK(TREE t, int k) {
    if (t == NULL) {
        return 0;
    }
    if (t->data < k) {
        return countNodesLessThanK(t->left, k) + countNodesLessThanK(t->right, k) + 1;
    }
    return countNodesLessThanK(t->left, k);
}

// Hàm tìm node có giá trị k trên cây
Node* findNode(TREE t, int k) {
    if (t == NULL || t->data == k) {
        return t;
    }
    if (k < t->data) {
        return findNode(t->left, k);
    }
    return findNode(t->right, k);
}

// Hàm xuất các node có 1 con
void printNodes1(TREE t) {
    if (t == NULL) {
        return;
    }
    if ((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL)) {
        cout << t->data << " ";
    }
    printNodes1(t->left);
    printNodes1(t->right);
}

// Hàm xuất các node có 2 con
void printNodes2(TREE t) {
    if (t == NULL) {
        return;
    }
    if (t->left != NULL && t->right != NULL) {
        cout << t->data << " ";
    }
    printNodes2(t->left);
    printNodes2(t->right);
}

// Hàm xuất các node lá
void printLeaves(TREE t) {
    if (t == NULL) {
        return;
    }
    if (t->left == NULL && t->right == NULL) {
        cout << t->data << " ";
    }
    printLeaves(t->left);
    printLeaves(t->right);
}

// Hàm xóa node có giá trị k trên cây
Node* deleteNode(TREE t, int k) {
    if (t == NULL) {
        return t;
    }
    if (k < t->data) {
        t->left = deleteNode(t->left, k);
    }
    else if (k > t->data) {
        t->right = deleteNode(t->right, k);
    }
    else {
        if (t->left == NULL) {
            Node* temp = t->right;
            delete t;
            return temp;
        }
        else if (t->right == NULL) {
            Node* temp = t->left;
            delete t;
            return temp;
        }
        Node* temp = findMin(t->right);
        t->data = temp->data;
        t->right = deleteNode(t->right, temp->data);
    }
    return t;
}

int main() {
    TREE t;
    Init(t);
    int k;
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    int arr[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        t = insertNode(t, arr[i]);
    }
    cout << "Cay nhi phan duoc tao la: ";
    LNR(t);
    cout << endl;
    int select;
    cout<<"------------------------------------------\n";
    cout<<"1.Duyet cay theo thu tu: LNR, NLR, LRN.\n";
    cout<<"2.Tinh đo sau cua cay.\n";
    cout<<"3.Tong so node tren cay.\n";
    cout<<"4. Tong so node la tren cay.\n";
    cout<<"5. Cho biet node co gia tri lon/nho nhat.\n";
    cout<<"6. Tong so node co gia tri lon/nho hon gia tri k cho truoc.\n";
    cout<<"7. Tim node co gia tri k.\n";
    cout<<"8. Xuat cac node co 1 con.\n";
    cout<<"9. Xuat cac node co 2 con.\n";
    cout<<"10. Xuat cac node la.\n";
    cout<<"11. Xoa node co gia tri k cho truoc.\n";
    cout<<"0.Thoat Chuong Trinh.\n";
    cout<<"-----------------------------------------\n";
    do{
        cout<<"Chon chuc nang thuc hien: ";
        cin>>select;
        switch(select){
        case 0:
            cout<<"Tam biet!\n";
            break;
        case 1:
            cout << "Duyet cay theo thu tu LNR: ";
            LNR(t);
            cout << endl;
            cout << "Duyet cay theo thu tu NLR: ";
            NLR(t);
            cout << endl;
            cout << "Duyet cay theo thu tu LRN: ";
            LRN(t);
            cout << endl;
            break;
        case 2:
            cout << "Do sau cua cay la: " << depth(t) << endl;
            break;
        case 3:
            cout << "Tong so node tren cay la: " << countNodes(t) << endl;
            break;
        case 4:
             cout << "Tong so node la tren cay la: " << countLeaves(t) << endl;
             break;
        case 5:{
            Node* maxNode = findMax(t);
            cout << "Node co gia tri lon nhat la: " << maxNode->data << endl;
            Node* minNode = findMin(t);
            cout << "Node co gia tri nho nhat la: " << minNode->data << endl;
        }
            break;
        case 6:
            {
            cout << "Nhap gia tri k: ";
            cin >> k;
            cout << "Tong so node co gia tri lon hon " << k << " la: " << countNodesGreaterThanK(t, k) << endl;
            cout << "Tong so node co gia tri nho hon " << k << " la: " << countNodesLessThanK(t, k) << endl;

            }
            break;
        case 7:
            {
            Node* nodeK = findNode(t, k);
            if (nodeK == NULL) cout << "Khong tim thay node co gia tri " << k << endl;
            else cout << "Node co gia tri " << k << " la: " << nodeK->data << endl;
            }
            break;
        case 8:
            cout << "Node co 1 con: ";
            printNodes1(t);
            cout << endl;
            break;
        case 9:
            cout << "Node co 2 con: ";
            printNodes2(t);
            cout<<endl;
            break;
        case 10:
            cout << "Xuat cac node la: ";
            printLeaves(t);
            cout << endl;
            break;
        case 11:
            int y;
            cout << "Nhap gia tri y de xoa: ";
            cin >> y;
            t = deleteNode(t, y);
            cout << " Thu tu sau khi xoa node co gia tri k cho truoc " << y << ": ";
            LNR(t);
            cout << endl;
            break;
        default: break;
        }
    } while (select != 0);
    return 0;

}
