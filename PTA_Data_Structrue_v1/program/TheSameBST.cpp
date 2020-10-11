#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{ 
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
BinTree Create(int n);
BinTree Insert(ElementType X, BinTree BST);
bool isSomorphism(BinTree BST, BinTree tree);
void isTheSameBST(int n, int m);
int main() {
    int n, m;
    cin >> n;
    while (n != 0) {
        cin >> m;
        isTheSameBST(n, m);
        cin >> n;
    }
    return 0;
}

BinTree Create(int n)
{
    BinTree BST = new (struct TNode);
    BST->Data = n;
    BST->Left = NULL;
    BST->Right = NULL;
    return BST;
}
BinTree Insert(ElementType X, BinTree BST) {
    if (BST == NULL) {
        BST = new (struct TNode);
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    } else {
        if (X < BST->Data) {
            BST->Left = Insert(X, BST->Left);  
        } else if (X > BST->Data) { 
            BST->Right = Insert(X, BST->Right);
        }
    }
    return BST;
}


bool isSomorphism(BinTree BST, BinTree tree)
{
    if (BST == NULL && tree == NULL) {
        return true;
    } else if (BST == NULL && tree != NULL || BST != NULL && tree == NULL){
        return false;
    } else if (BST->Data != tree->Data) {
        return false;
    } else {
        return isSomorphism(BST->Left, tree->Left) && isSomorphism(BST->Right, tree->Right);
    }
}
void isTheSameBST(int n, int m)
{
    ElementType data;
    cin >> data;
    BinTree BST = Create(data);
    for (int i = 1; i <= n - 1; ++i) {
        cin >> data;
        Insert(data, BST);
    }
    for (int i = 0; i <= m - 1; ++i) {
        cin >> data;
        BinTree tree = Create(data);
        for (int j = 1; j <= n - 1; ++j) {
            cin >> data;
            Insert(data, tree);
        }
        if (isSomorphism(BST, tree)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}