#include <bits/stdc++.h>
using namespace std;
using ElementType = char;
struct TNode {
    char data;
    struct TNode *left;
    struct TNode *right;
};

struct TNode *BinTreeFromOderings(char PreOder[], char InOder[], int n)
{
    if (n == 0) {
        return NULL;
    }
    struct TNode *BT = new (struct TNode);
    BT->data = PreOder[0];
    BT->left = NULL;
    BT->right = NULL;
    int RootIndex = 0;
    for ( ; RootIndex <= n - 1; ++RootIndex) {
        if (InOder[RootIndex] == BT->data) {
            break;
        }
    }
    BT->left = BinTreeFromOderings(PreOder + 1, InOder, RootIndex);
    BT->right = BinTreeFromOderings(PreOder + RootIndex + 1, InOder + RootIndex + 1, n - RootIndex - 1);
    return BT;
}

int getHeight(struct TNode* BT)
{
    if (BT == nullptr) {
        return 0;
    } else {
        return max(getHeight(BT->left) + 1, getHeight(BT->right) + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    char PreOder[n+1], InOrder[n+1];
    cin >> PreOder >> InOrder;
    struct TNode *BT = BinTreeFromOderings(PreOder, InOrder, n);
    cout << getHeight(BT) << endl;
    return 0;
}