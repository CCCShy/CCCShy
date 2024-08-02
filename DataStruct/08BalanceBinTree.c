#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct AVLNode* AVLTree;

struct AVLNode
{
	ElementType Data;//节点数据
	AVLTree Left;//左子树
	AVLTree Right;//右子树
	int Height;//树高
};

int Max(int a, int b)
{
	return a > b ? a : b;
}

int GetHeight(AVLTree T)
{
	return T->Height;
}

AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(A->Height, GetHeight(B->Right)) + 1;
	return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
	/*自己写的，有点复杂
	AVLTree B = A->Left;
	AVLTree C = B->Right;
	A->Left = C->Right;
	B->Right = C->Left;
	C->Left = B;
	C->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;
	C->Height = Max(A->Height, B->Height) + 1;
	return C;*/

	//A必须有一个左子结点B，B必须有一个右子结点C
	//A、B、C做两次单旋
	A->Left = SingleRightRotation(A->Left);//将B与C进行右单旋，C被返回
	return SingleLeftRotation(A);//将A与C进行左单旋，C被返回
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}

AVLTree Insert(AVLTree T, ElementType X)
{
	if (!T)//若为空树，则新建包含一个结点的树
	{
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Left = T->Right = NULL;
		T->Height = 1;
	}
	else if (X < T->Data)
	{
		T->Left = Insert(T->Left, X);
		if (GetHight(T->Left) - GetHight(T->Right) == 2)
		{
			if (X < T->Left->Data)
				T = SingleLeftRotation(T);
			else
				T = DoubleLeftRightRotation(T);
		}
	}
	else if (X > T->Data)
	{
		T->Right = Insert(T->Right, X);
		if (GetHight(T->Left) - GetHight(T->Right) == -2)
		{
			if (X > T->Right->Data)
				T = SingleRightRotation(T);
			else
				T = DoubleRightLeftRotation(T);
		}
	}
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;
}

int main()
{
	return 0;
}




//慕课代码：AVL树的旋转与插入
typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL树类型 */
struct AVLNode{
    ElementType Data; /* 结点数据 */
    AVLTree Left;     /* 指向左子树 */
    AVLTree Right;    /* 指向右子树 */
    int Height;       /* 树高 */
};

int Max ( int a, int b )
{
    return a > b ? a : b;
}

AVLTree SingleLeftRotation ( AVLTree A )
{ /* 注意：A必须有一个左子结点B */
  /* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */     

    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    B->Height = Max( GetHeight(B->Left), A->Height ) + 1;
 
    return B;
}

AVLTree DoubleLeftRightRotation ( AVLTree A )
{ /* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
  /* 将A、B与C做两次单旋，返回新的根结点C */
    
    /* 将B与C做右单旋，C被返回 */
    A->Left = SingleRightRotation(A->Left);
    /* 将A与C做左单旋，C被返回 */
    return SingleLeftRotation(A);
}

/*************************************/
/* 对称的右单旋与右-左双旋请自己实现 */
/*************************************/

AVLTree Insert( AVLTree T, ElementType X )
{ /* 将X插入AVL树T中，并且返回调整后的AVL树 */
    if ( !T ) { /* 若插入空树，则新建包含一个结点的树 */
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    } /* if (插入空树) 结束 */

    else if ( X < T->Data ) {
        /* 插入T的左子树 */
        T->Left = Insert( T->Left, X);
        /* 如果需要左旋 */
        if ( GetHeight(T->Left)-GetHeight(T->Right) == 2 )
            if ( X < T->Left->Data ) 
               T = SingleLeftRotation(T);      /* 左单旋 */
            else 
               T = DoubleLeftRightRotation(T); /* 左-右双旋 */
    } /* else if (插入左子树) 结束 */
    
    else if ( X > T->Data ) {
        /* 插入T的右子树 */
        T->Right = Insert( T->Right, X );
        /* 如果需要右旋 */
        if ( GetHeight(T->Left)-GetHeight(T->Right) == -2 )
            if ( X > T->Right->Data ) 
               T = SingleRightRotation(T);     /* 右单旋 */
            else 
               T = DoubleRightLeftRotation(T); /* 右-左双旋 */
    } /* else if (插入右子树) 结束 */

    /* else X == T->Data，无须插入 */

    /* 别忘了更新树高 */
    T->Height = Max( GetHeight(T->Left), GetHeight(T->Right) ) + 1;
    
    return T;
}