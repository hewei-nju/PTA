#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
BinTree Insert( BinTree BST, ElementType X )
{
    if (BST == NULL) {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    } else {
        if (X < BST->Data) {
            BST->Left = Insert(BST->Left, X);
        } else if (X > BST->Data) {
            BST->Right = Insert(BST->Right, X);
        }
    }
    return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{
    Position Tmp;
    if (BST == NULL) {  // 二叉搜索树为空
        printf("Not Found\n");
    } else if (X < BST->Data) {  // 要删除的元素X小于根节点元素，从左边去继续寻找删除
        BST->Left = Delete(BST->Left, X);
    } else if (X > BST->Data) {  // 要删除的元素X大于根节点元素，从右边去继续寻找删除
        BST->Right = Delete(BST->Right, X);
    } else {  // 等于，表示已经找到
        if (BST->Left != NULL && BST->Right != NULL) {  // 要删除元素的左右子树均存在
            Tmp = FindMin(BST->Right);  // 在有子树中寻找最小的元素，并返回地址
            BST->Data = Tmp->Data;  // 直接将要删除的元素的存储空间赋值右边最小元素
            BST->Right = Delete(BST->Right, BST->Data);  // 然后继续下去
        } else { // 至少有一个子树不存在
            // 要删除的元素的存储地址赋值Tmp,让BST指向其后的一个子树orNULL，并释放原来的空间
            Tmp = BST;  
            if (BST->Left == NULL) {  // 左子树不存在
                BST = BST->Right;  // 让BST指向右子树(可能为NULL)
            } else if (BST->Right == NULL) {  // 有子树不存在
                BST = BST->Left;  // 让BST指向左子树(可能为NULL)
            }
            free(Tmp);  // 释放掉要删除元素的空间
        }
    }
    return BST;
}
Position Find( BinTree BST, ElementType X )
{
    if (BST == NULL) {
        return NULL;
    }
    Position res = BST;
    while (res != NULL) {
        if (res->Data == X) {
            return res;
        } else if (res->Data < X) {
            res = res->Right;
        } else {
            res = res->Left;
        }
    }
    return NULL;
}
Position FindMin( BinTree BST )
{
    if (BST == NULL) {
        return NULL;
    }
    Position res = BST;
    while (res->Left != NULL) {
        res = res->Left;
    }
    return res;
}
Position FindMax( BinTree BST )
{
    if (BST == NULL) {
        return NULL;
    }
    Position res = BST;
    while (res->Right != NULL) {
        res = res->Right;
    }
    return res;
}