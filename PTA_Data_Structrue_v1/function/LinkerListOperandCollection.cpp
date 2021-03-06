#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
Position Find( List L, ElementType X )
{
    List p = L;
    while (p != NULL) {
        if (p->Data == X) {
            return p;
        }
        p = p->Next;
    }
    return ERROR;
}
List Insert( List L, ElementType X, Position P )
{
    if (P == L) {
        List res = (List)malloc(sizeof(struct LNode));
        res->Data = X;
        res->Next = L;
        return res;
    } else {
        List tmp = (List)malloc(sizeof(struct LNode));
        tmp->Data = X;
        tmp->Next = NULL;
        List res = L;
        while (L != NULL) {
            if (L->Next == P) {
                L->Next = tmp;
                tmp->Next = P;
                return res;
            }
            L = L->Next;
        }
        printf("Wrong Position for Insertion\n");
        return ERROR;
    }
}

List Delete( List L, Position P )
{
    if (L == NULL || P == NULL) {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    if (P == L) {
        List res = L->Next;
        free(P);
        return res;
    } else {
        List res = L;
        while (L != NULL) {
            if (L->Next == P) {
                L->Next = P->Next;
                free(P);
                return res;
            }
            L = L->Next;
        }
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
}