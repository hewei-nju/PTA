#include <bits/stdc++.h>
using namespace std;

struct TNode {
    int *data;
    int size;
    int capacity;
};

using BinTree = struct TNode *;

BinTree Create(int MaxSize)
{
    BinTree T = new (struct TNode);
    T->data = new int[MaxSize + 1];
    T->data[0] = 0;
    T->size = 0;
    T->capacity = MaxSize;
    return T;
}

bool IsEmpty(BinTree T)
{
    return T->size == 0;
}

bool IsFull(BinTree T)
{
    return T->capacity == T->size;
}

int main()
{
    int n;
    cin >> n;
    BinTree T = Create(n);
    for (int i = 0; i <= n - 1; ++i) {
        cin >> T->data[++T->size];
    }
    int i, j;
    cin >> i >> j;
    if (T->data[i] == 0) {
        cout << "ERROR: " << "T[" << i << "] is NULL" << endl;
        return 0;
    }
    if (T->data[j] == 0) {
        cout << "ERROR: " << "T[" << j << "] is NULL" << endl;
        return 0;
    }

    while (i != j) {
        if (i > j) {
            i /= 2;
        } else if (j > i) {
            j /= 2;
        }
    }
    cout << i << " " << T->data[i] << endl;
}