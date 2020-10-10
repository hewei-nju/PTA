#include <bits/stdc++.h>
using namespace std;

struct HNode{
    int *data;
    int size;
    int capacity;
};

using MaxHeap = struct HNode *;

MaxHeap Create(int MaxSize)
{
    MaxHeap H = new (struct HNode);
    H->data = new int[MaxSize + 1];
    H->size = 0;
    H->capacity = MaxSize;
    H->data[0] = -10001;
    return H;
}

bool IsEmpty(MaxHeap H)
{
    return H->size == 0;
}

bool IsFull(MaxHeap H)
{
    return H->size == H->capacity;
}

bool Insert(MaxHeap H, int X)
{
    if (IsFull(H)) {
        cout << "堆已空！" << endl;
        return false;
    }
    H->data[++H->size] = X;
    int i = H->size;
    for ( ; H->data[i / 2] > X; i /= 2) {
        int temp = H->data[i / 2];
        H->data[i / 2] = H->data[i];
        H->data[i] = temp;
    }
    //H->data[i] = X;
    return true;
}

int DeleteMin(MaxHeap H)
{
    int res = H->data[1];
    int i = H->size--;
    H->data[1] = H->data[i];
    for (i = 1; 2 * i <= H->size; ) {
        if (H->data[i] > H->data[2 * i]) {
            int temp = H->data[2 * i];
            H->data[2 * i] = H->data[i];
            H->data[i] = temp;
        } else if ((2 * i + 1) <= H->size && H->data[i] > H->data[ 2 * i + 1]) {
            int temp = H->data[2 * i + 1];
            H->data[2 * i + 1] = H->data[i];
            H->data[i] = temp;
        } else if ((2 * i + 1) <= H->size && H->data[i] <= H->data[2 * i] && H->data[i] <= H->data[2 * i + 1]) {
            break;
        } else if (H->data[i] <= H->data[2 * i]) {
            break;
        }
    }
    return res;
}

void PrintRoad(MaxHeap H, int pos)
{
    for (int j = pos; j >= 1; j /= 2) {
        if (j == pos) {
                cout << H->data[j];
        } else {
                cout << " " << H->data[j];
        }
    }
    cout << endl;
}

int main()
{
    int n, m, num;
    cin >> n >> m;
    int arr[m];
    MaxHeap H = Create(n);
    for (int i = 0; i <= n - 1; ++i) {
        cin >> num;
        Insert(H, num);
    }
    for (int i = 0; i <= m - 1; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i <= m - 1; ++i) {
        PrintRoad(H, arr[i]);
    }

    return 0;
}