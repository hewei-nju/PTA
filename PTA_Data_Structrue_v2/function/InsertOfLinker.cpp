#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

List Insert( List L, ElementType X )
{
    List res = L; 
    List p = (List)malloc(sizeof(struct Node));
    p->Data = X;
    p->Next = NULL;
    if (L->Next == NULL) {  
        L->Next = p;
        return res;
    }
    L = L->Next;
    if (L->Data > X) {
        res->Next = p;
        p->Next = L;
        return res;
    }
    while (L != NULL) {
        if (L->Data < X && L->Next == NULL) {  
            L->Next = p;
            return res; 
        } else if (L->Data < X && L->Next->Data > X) {  
            p->Next = L->Next;
            L->Next = p;
            return res; 
        }
        L = L->Next;
    }
}/* 你的代码将被嵌在这里 */
