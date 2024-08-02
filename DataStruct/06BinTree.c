#include<stdio.h>
#include<stdlib.h>

// # 二叉搜索树 Binary Search Tree
// 1. 非空左子树所有键值小于根节点的键值
// 2. 非空右子树所有键值大于根节点的键值
// 3. 左右子树都是二叉搜索树
  
// 操作的函数:  
// 1. Position Find( ElementType X, BinTree BST ):从二叉搜索树BST 中查找元素X，返回其所在结点的地址;
// 2. Position FindMin( BinTree BST ):从二叉搜索树BST中查找并返回 最小元素所在结点的地址;
// 3. Position FindMax( BinTree BST ) :从二叉搜索树BST中查找并返回 最大元素所在结点的地址。
// 4. BinTree Insert( ElementType X, BinTree BST ) 插入
// 5. BinTree Delete( ElementType X, BinTree BST ) 删除

int main()
{
    return 0;
}






void InorderTraversal( BinTree BT )
{
    if( BT ) {
        InorderTraversal( BT->Left );
        /* 此处假设对BT结点的访问就是打印数据 */
        printf("%d ", BT->Data); /* 假设数据为整型 */
        InorderTraversal( BT->Right );
    }
}

void PreorderTraversal( BinTree BT )
{
    if( BT ) {
        printf("%d ", BT->Data );
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}

void PostorderTraversal( BinTree BT )
{
    if( BT ) {
        PostorderTraversal( BT->Left );
        PostorderTraversal( BT->Right );
        printf("%d ", BT->Data);
    }
}

void LevelorderTraversal ( BinTree BT )
{ 
    Queue Q; 
    BinTree T;

    if ( !BT ) return; /* 若是空树则直接返回 */
    
    Q = CreatQueue(); /* 创建空队列Q */
    AddQ( Q, BT );
    while ( !IsEmpty(Q) ) {
        T = DeleteQ( Q );
        printf("%d ", T->Data); /* 访问取出队列的结点 */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )  AddQ( Q, T->Right );
    }
}