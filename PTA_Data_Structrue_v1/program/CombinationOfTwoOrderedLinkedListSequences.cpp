#include <bits/stdc++.h>
using namespace std;
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List CreateList();
List Merge(List L1, List L2);
void Print(List L);
int main()
{
    List L1, L2, L;
    L1 = CreateList();
    L2 = CreateList();
    L = Merge(L1, L2);
    Print(L);
    return 0;
}

List CreateList()
{
    List Head, L;
    Head = new (struct Node);
    Head->Next = nullptr;
    L = Head;
    int data;
    cin >> data;
    while (data != -1) {
        struct Node *NewNode = new (struct Node);
        NewNode->Data = data;
        NewNode->Next = nullptr;
        L->Next = NewNode;
        L = L->Next;
        cin >> data;
    }
    return Head;
}
List Merge(List L1, List L2)
{
    List Head = (List)malloc(sizeof(struct Node));
    Head->Next = NULL;
    List L = Head;
    List p1 = L1->Next;
    List p2 = L2->Next;
    while (p1 != NULL && p2 != NULL) {
        if (p1->Data < p2->Data) {
            L->Next = p1;
            p1 = p1->Next;
            L = L->Next;
        } else {
            L->Next = p2;
            p2 = p2->Next;
            L = L->Next;
        }
    }
    if (p1 != NULL) {
        L->Next = p1;
    }
    if (p2 != NULL) {
        L->Next = p2;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return Head;
}
void Print(List L)
{
    if (L == nullptr || L->Next == nullptr) {
        cout << "NULL" << endl;
    } else {
        L = L->Next;
        cout << L->Data;
        L = L->Next;
        while (L != nullptr) {
            cout << " " << L->Data;
            L = L->Next;
        }
    }
}