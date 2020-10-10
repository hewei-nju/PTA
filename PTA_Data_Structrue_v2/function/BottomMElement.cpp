#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Find( List L, int m )
{
    List p = L;
    int len = 0;
    while (p != NULL) {
        len += 1;
        p = p->Next;
    }
    len = len - m;
    if (len <= 0) {
        return ERROR;
    }
    while(len > 0) {
        L = L->Next;
        len -= 1;
    }
    return L->Data;

}