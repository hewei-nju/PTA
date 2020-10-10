#include <bits/stdc++.h>
using namespace std;

typedef struct TNode *Position; 
typedef Position BinTree; 
struct TNode{ 
    int Data; 
    BinTree Left;   
    BinTree Right;    
};


BinTree CreateBinTree(int Mid[], int Post[], int n);  
void PreOrderTraversal(BinTree BT, int res[], int &n);


int main() {
    int n;
    cin >> n;
    int Post[n];
    int Mid[n];
    int res[n];
    int i = 0;
    for (int i = 0; i <= n - 1; ++i) {
        cin >> Post[i];
    }
    for (int i = 0; i <= n - 1; ++i) {
        cin >> Mid[i];
    }
    BinTree BT = CreateBinTree(Mid, Post, n);
    PreOrderTraversal(BT, res, i);
    for (i = 0; i <= n - 1; ++i) {
        if (i == 0) {
            cout << "Preorder: " << res[i];
        } else {
            cout << " " << res[i];
        }
    }
    return 0;
}

BinTree CreateBinTree(int Mid[], int Post[], int n) 
{
    if (n <= 0) {
        return NULL;
    }
    BinTree BT = new (struct TNode);
    BT->Data = Post[n-1];
    BT->Left = NULL;
    BT->Right = NULL;
    int rootIndex = 0;
    for ( ; rootIndex <= n - 1; ++rootIndex) {
        if (Mid[rootIndex] == BT->Data) {
            break;
        }
    }
    BT->Left = CreateBinTree(Mid, Post, rootIndex);
    BT->Right = CreateBinTree(Mid + rootIndex + 1, Post + rootIndex, n - rootIndex - 1);
    return BT;
}



void PreOrderTraversal(BinTree BT, int res[], int &i) 
{
    if (BT != NULL) {
         res[i++] = BT->Data;
        PreOrderTraversal(BT->Left, res, i);
        PreOrderTraversal(BT->Right, res, i);
    }
}
