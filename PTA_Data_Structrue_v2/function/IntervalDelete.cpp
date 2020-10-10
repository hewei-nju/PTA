#include <stdio.h>
#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
List Delete( List L, ElementType minD, ElementType maxD );

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );

    return 0;
}

/* 你的代码将被嵌在这里 */
List Delete( List L, ElementType minD, ElementType maxD )
{
    if (L == NULL) {
        return L;
    }
    ElementType res[L->Last+1];
    int len = 0;
    for (int i = 0; i <= L->Last; ++i) {
        if (L->Data[i] >= maxD || L->Data[i] <= minD) {
            res[len++] = L->Data[i];
        }
    }
    for (int i = 0; i <= len - 1; ++i) {
        L->Data[i] = res[i];
    }
    L->Last = len - 1;
    return L;
}
