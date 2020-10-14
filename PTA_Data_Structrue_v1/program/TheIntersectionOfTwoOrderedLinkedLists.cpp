#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
};
using List = struct Node *;
List CreateList();
List Union(List L1, List L2);
void Print(List L);
int main()
{
    List L1, L2, L;
    L1 = CreateList();
    L2 = CreateList();
    L = Union(L1, L2);
    Print(L);
    return 0;
}

List CreateList()
{
    List L, Head;
    Head = new (struct Node);
    Head->next = nullptr;
    L = Head;
    int data;
    while (cin >> data, data != -1) {
        List NewNode = new (struct Node);
        NewNode->data = data;
        NewNode->next = nullptr;
        L->next = NewNode;
        L = L->next;
    }
    return Head;
}
List Union(List L1, List L2)
{
    L1 = L1->next;
    L2 = L2->next;
    List L, Head;
    Head = new (struct Node);
    Head->next = nullptr;
    L = Head;
    while (L1 != nullptr && L2 != nullptr) {
        if (L1->data > L2->data) {
            L2 = L2->next;
        } else if (L1->data < L2->data) {
            L1 = L1->next;
        } else {
            List NewNode = new (struct Node);
            NewNode->data = L1->data;
            NewNode->next = nullptr;
            L->next = NewNode;
            L = L->next;
            L1 = L1->next;
            L2 = L2->next;
        }
    } 
    return Head;
}
void Print(List L) 
{
    L = L->next;
    int cnt = 0;
    if (L == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    while (L != nullptr) {
        if (cnt == 0) {
            cout << L->data;
        } else {
            cout << " " << L->data;
        }
        cnt += 1;
        L = L->next;
    }
}