#include <bits/stdc++.h>
using namespace std;
typedef int ElementType;

typedef struct AVLNode *Position;  // Position == struct AVLNode *

typedef Position AVLTree; /* AVL树类型 */

struct AVLNode{
    ElementType Data; /* 结点数据 */
    AVLTree Left;     /* 指向左子树 */
    AVLTree Right;    /* 指向右子树 */
    int Height;       /* 树高 */
};


int Max (int a, int b) {
    return a > b ? a : b;
}

 
 int GetHeight(AVLTree A) {
     if (A == NULL) {
         return 0;
     } else {
         return Max(GetHeight(A->Left) + 1, GetHeight(A->Right) + 1);
     }
 }


/* 注意：A必须有一个左子结点B */
AVLTree SingleLeftRotation (AVLTree A) {
    //左单旋，则二叉树A必须是有一个左子节点B，然后在B的左儿子处插入了一个新的节点 
  /* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */     

    AVLTree B = A->Left;  // 先获取二叉树A的左儿子B
    A->Left = B->Right;   // 让A的左儿子处指向B的右儿子
    B->Right = A;         // 让B的右儿子指向A （结合改变的图解来理解记忆）
    // 调整后注意二者的树的高度
    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Left), A->Height) + 1;
  
    return B;
}


AVLTree SingleRightRotation(AVLTree A) {
    AVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    A->Height = Max(GetHeight(A->Right), GetHeight(A->Left)) + 1;
    B->Height = Max(GetHeight(B->Right), A->Height) + 1;

    return B;
}
 

AVLTree DoubleLeftRightRotation (AVLTree A) { /* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
  /* 将A、B与C做两次单旋，返回新的根结点C */
     
    /* 将B与C做右单旋，C被返回 */
    A->Left = SingleRightRotation(A->Left);
    /* 将A与C做左单旋，C被返回 */
    return SingleLeftRotation(A);
}


AVLTree DoubleRightLeftRotation (AVLTree A) {
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}
 
/*************************************/
/* 对称的右单旋与右-左双旋请自己实现 */
/*************************************/
 
AVLTree Insert(AVLTree T, ElementType X) { /* 将X插入AVL树T中，并且返回调整后的AVL树 */
    if (!T) { /* 若插入空树，则新建包含一个结点的树 */
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    } /* if (插入空树) 结束 */
 
    else if (X < T->Data) {
        /* 插入T的左子树 */
        T->Left = Insert(T->Left, X);
        /* 如果需要左旋 */
        if (GetHeight(T->Left)-GetHeight(T->Right) == 2)
            if (X < T->Left->Data) 
               T = SingleLeftRotation(T);      /* 左单旋 */
            else 
               T = DoubleLeftRightRotation(T); /* 左-右双旋 */
    } /* else if (插入左子树) 结束 */
     
    else if (X > T->Data) {
        /* 插入T的右子树 */
        T->Right = Insert(T->Right, X);
        /* 如果需要右旋 */
        if (GetHeight(T->Left)-GetHeight(T->Right) == -2)
            if (X > T->Right->Data) 
               T = SingleRightRotation(T);     /* 右单旋 */
            else 
               T = DoubleRightLeftRotation(T); /* 右-左双旋 */
    } /* else if (插入右子树) 结束 */
 
    /* else X == T->Data，无须插入 */
 
    /* 别忘了更新树高 */
    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
     
    return T;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i <= n - 1; ++i) {
        cin >> arr[i];
    }
    struct AVLNode *AVLtree = new (struct AVLNode);
    AVLtree->Data = arr[0];
    AVLtree->Right = NULL;
    AVLtree->Left = NULL;
    AVLtree->Height = GetHeight(AVLtree);
    for (int i = 1; i <= n - 1; ++i) {
        AVLtree = Insert(AVLtree, arr[i]);
    }

    cout << AVLtree->Data << endl;
    return 0;
}