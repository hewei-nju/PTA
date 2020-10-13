#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    struct Node *pre;
};
using List = struct Node *;
void Kth() 
{
    List list = new (struct Node);
    List Head = list, tail;
    List tmp;
    int Kth, n = 0;
    cin >> Kth;
    int num;
    while (true) {
        cin >> num;
        if (num >= 0) {
            n += 1;
            tmp = new (struct Node);
            tmp->data = num;
            tmp->next = nullptr;
            tmp->pre = list;
            list->next = tmp;
            list = list->next;
        } else {
            break;
        }
    }
    tail = list;
    if (n - Kth < 0) {
        cout << "NULL" << endl;
    } else if (Kth > n/2) {
        Kth = n - Kth;
        Head = Head->next;
        while (Kth > 0) {
            Kth -= 1;
            Head = Head->next;
        }
        cout << Head->data << endl;
    } else {
        while (Kth > 1) {
            Kth -= 1;
            tail = tail->pre;
        }
        cout << tail->data << endl;
    }
}
int main()
{
    Kth();
    return 0;
}