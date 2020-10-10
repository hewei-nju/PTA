#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );

    return 0;
}

/* 你的代码将被嵌在这里 */
bool Insert( List L, ElementType X )
{
    if (L->Last == MAXSIZE - 1) {
        return false;
    }
    Position head = 0, tail = L->Last, p = (head + tail) / 2;
    while (head <= tail) {
        if (L->Data[p] == X) {
            return false;
        } else if (L->Data[p] < X) {
            if (p == 0) {
                for (Position i = L->Last; i >= 0; --i) {
                    L->Data[i+1] = L->Data[i];
                }
                L->Data[0] = X;
                L->Last += 1;
                return true;
            } else if (L->Data[p-1] > X) {
                for (Position i = L->Last; i >= p; --i) {
                    L->Data[i+1] = L->Data[i];
                }
                L->Data[p] = X;
                L->Last += 1;
                return true;
            } else {
                tail = p - 1;
            }
        } else {
            if (p == L->Last) {
                L->Data[++L->Last] = X;
                return true;
            } else if (L->Data[p+1] < X) {
                for (Position i = L->Last; i >= p + 1; --i) {
                    L->Data[i+1] = L->Data[i];
                }
                L->Data[p+1] = X;
                L->Last += 1;
                return true;
            } else {
                head = p + 1;
            }
        }
        p = (head + tail) / 2;
    }
}