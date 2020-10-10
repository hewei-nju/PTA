#include <bits/stdc++.h>
using namespace std;
#define MaxSize 100001
struct Node {
    int Data[MaxSize];
    int Top;
};
using Stack = struct Node *;

void Push(Stack S, int x)
{
    S->Data[++S->Top] = x;
}

void Pop(Stack S)
{
    cout << S->Data[S->Top--];
}

void SumEnhanced(int x, int n)
{
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    Stack S = new (struct Node);
    S->Top = -1;
    int carry = 0;
    int part_sum = 0;
    for (int i = n; i >= 1; --i) {
        part_sum = x * i + carry;
        carry = part_sum / 10;
        part_sum %= 10;
        Push(S, part_sum);
    }
    if (carry != 0) {
        Push(S, carry);
    }

    while(S->Top >= 0) {
        Pop(S);
    }
}

int main()
{
    int x, n;
    cin >> x >> n;
    SumEnhanced(x, n);
    return 0;
}