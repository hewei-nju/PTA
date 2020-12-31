#include <bits/stdc++.h>
using namespace std;
using ElementType = int;
const int ERROR = -65536;
struct SNode{
    ElementType *data;
    int Top;
    int MaxSize;
};
using Stack = struct SNode*;
Stack CreateStack(int size);
int IsFull(Stack S);
int IsEmpty(Stack S);
void Push(Stack S, ElementType item);
ElementType Pop(Stack S);
struct QNode {
    Stack S1;  // 缓冲栈
    Stack S2;  // 存储站
    int MaxSize;
};
using Queue = struct QNode*;
Queue CreateQueue(int n1, int n2);
int QueueIsFull(Queue Q);
int QueueIsEmpty(Queue Q);
void AddQ(Queue Q, ElementType item);
ElementType DeleteQ(Queue Q);

int main()
{
    int n, m;
    cin >> n >> m;
    Queue Q = CreateQueue(n, m);
    char INS;
    ElementType item;
    cin >> INS;
    while (INS != 'T') {
        switch (INS) {
            case 'A':
                cin >> item;
                AddQ(Q, item);
                break;
            case 'D':
                int res = DeleteQ(Q);
                if (res != ERROR) {
                    cout << res << endl;
                }
                break;
        }
        cin >> INS;
    }
}

Stack CreateStack(int size)
{
    Stack S = new (struct SNode);
    S->data = new ElementType[size];
    S->MaxSize = size;
    S->Top = -1;
    return S;
}
int IsFull(Stack S)
{
    if (S->Top == S->MaxSize - 1) {
        return 1;
    } else {
        return 0;
    }
}
int IsEmpty(Stack S)
{
    if (S->Top == -1) {
        return 1;
    } else {
        return 0;
    }
}
void Push(Stack S, ElementType item)
{
    if (IsFull(S)) {
        cout << "ERROR:Full" << endl;
    } else {
        S->data[++S->Top] = item;
    }
}
ElementType Pop(Stack S)
{
    if (IsEmpty(S)) {
        cout << "ERROR:Empty" << endl;
    } else {
        return S->data[S->Top--];
    }
    return ERROR;
}
Queue CreateQueue(int n1, int n2)
{
    Queue Q = new (struct QNode);
    if (n1 > n2) {
        Q->S1 = CreateStack(n2);
        Q->S2 = CreateStack(n2);
    } else {
        Q->S1 = CreateStack(n1);
        Q->S2 = CreateStack(n1);
    }
    Q->MaxSize = 2 * min(n1, n2);
    return Q;
}
int QueueIsFull(Queue Q)
{
    if (IsFull(Q->S1) && IsFull(Q->S2)) {
        return 1;
    } else {
        return 0;
    }
}
int QueueIsEmpty(Queue Q)
{
    if (IsEmpty(Q->S1) && IsEmpty(Q->S2)) {
        return 1;
    } else {
        return 0;
    }
}
void AddQ(Queue Q, ElementType item)
{
    if (QueueIsFull(Q)) {
        cout << "ERROR:Full" << endl;
    } else {
        if (!IsEmpty(Q->S2) && IsFull(Q->S1)) {
            cout << "ERROR:Full" << endl;
        } else if (!IsEmpty(Q->S2) && !IsFull(Q->S1)) {
            Push(Q->S1, item);
        } else if (IsEmpty(Q->S2) && IsFull(Q->S1)) {
            while (!IsEmpty(Q->S1)) {
                Push(Q->S2, Pop(Q->S1));
            }
            Push(Q->S1, item);
        } else {
            Push(Q->S1, item);
        }
    }
}
ElementType DeleteQ(Queue Q)
{
    if (QueueIsEmpty(Q)) {
        cout << "ERROR:Empty" << endl;
        return ERROR;
    } else {
        if (IsEmpty(Q->S2)) {
            while (!IsEmpty(Q->S1)) {
                Push(Q->S2, Pop(Q->S1));
            }
        }
        return Pop(Q->S2);
    }
}