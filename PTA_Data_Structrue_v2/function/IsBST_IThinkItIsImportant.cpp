#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* 由裁判实现，细节不表 */
bool IsBST ( BinTree T );

int main()
{
    BinTree T;

    T = BuildTree();
    if ( IsBST(T) ) printf("Yes\n");
    else printf("No\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
bool IsBST ( BinTree T )
{
    if (T == NULL) {
        return true;
    } else {
        if (T->Left != NULL) {
            if (T->Data <= T->Left->Data) {
                return false;
            } else if (T->Left->Right != NULL) {
                if (T->Left->Right->Data >= T->Data) {
                    return false;
                }
            }
            return IsBST(T->Left);
        } else if (T->Right != NULL) {
            if (T->Data >= T->Right->Data) {
                return false;
            } else if (T->Right->Left != NULL) {
                if (T->Right->Left->Data <= T->Data) {
                    return false;
                }
            }
            return IsBST(T->Right);
        } else {
            return true;
        }
    }
}
