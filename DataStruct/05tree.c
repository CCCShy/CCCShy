#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

// # 树与树的表示
// 查找 Searching
// * 静态查找 集合是固定的,没有插入和删除
// * 动态查找 集合中的记录是动态变化的,可以插入和删除

// ### 静态查找 Sequential Search
// 方法一：顺序查找:
// 结构体：
struct Lnode
{
    int Element[MAXSIZE];
    int length;
};
typedef struct Lnode *List;

int SequentialSearch(List Tb1,int K)
{
    int i;
    Tb1 -> Element[0] = K;//建立哨兵
    for(i = Tb1 -> length;Tb1 -> Element[i] != K;i--);
    return i;//查找成功返回所在下标，未找到则返回0
}
// 顺序查找算法的时间复杂度为O(n) 

// ### 二分查找 Binary Search  
// 函数:

int BinarySearch(List Tb2,int K)//二分法查找前提是数组是按照升序或者降序排列，此函数默认为升序
{//在数组Tb2中查找元素为K的数据元素
    int left,mid,right,NotFound = -1;
    left = 1;
    right = Tb2 -> length;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(K > Tb2 -> Element[mid])
            left = mid + 1;
        else if(K < Tb2 -> Element[mid])
            right = mid - 1;
        else
            return mid;
    }
    return NotFound;
}
// 二分查找算法具有对数的时间复杂度O(logN)  
// 判定树:  
// 判定树上每个结点需要的查找次数刚好 为该结点所在的层数.  
// n个结点的判定树的深度 为[log2n]+1.  

// ## 树 Tree  
// 定义:n(n≥0)个结点构成的有限集合  
// 子树是不相交的,除了根结点外，每个结点有且仅有一个父结点  
// 结点的度(Degree):结点的子树个数  
// 树的度:树的所有结点中最大的度数  
// 结点的层次(Level):规定根结点在1层， 其它任一结点的层数是其父结点的层数加1。  
// 树的深度(Depth):树中所有结点中的最 大层次是这棵树的深度。

// ### 二叉树  
// 度为2的树,可以为空.若不为空由根节点和左子树和右子树
// * 一个二叉树第 i 层的最大结点数为:2^(i-1)  
// * 深度为k的二叉树有最大结点总数为: 2^k -1
// * 对任何非空二叉树T，若$n_0$表示叶结点的个数、$n_2$是度为2的非叶结点个数，那么两者满足关系$n_0 = n_2 +1$  
// 证明: 总边数=总节点数-1 (因为根没有向上的边)  
// 总边数= n0 + n1 +n2 -1  
// 总边数 = 0*n0 + 1*n1 + 2*n2  (往下看)

// 二叉树的存储结构  
// 1. 顺序存储结构  
// 完全二叉树  
// 父节点:i/2  
// 左子节点: 2i  
// 右子节点: 2i+1  

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode
{
    int Data;
    BinTree Left;
    BinTree Right;
};

// 1. 先序遍历  PreOrder Traversal
// 根节点->左子树->右子树  
void PreOrderTraversal(BinTree BT)
{
    printf("%d ",BT -> Data);
    PreOrderTraversal(BT -> Left);
    PreOrderTraversal(BT -> Right);
}

// 2. 中序遍历 InOrderT Traversal  
// 左子树->根节点->右子树    
void InOrderTraversal(BinTree BT)
{
    InOrderTraversal(BT -> Left);
    printf("%d ",BT -> Data);
    InOrderTraversal(BT -> Right);
}

// 3. 后序遍历 Post-Order Traversal 
// 左子树->右子树->根节点 
void PostOrderTraversal(BinTree BT)
{
    PostOrderTraversal(BT -> Left);
    PostOrderTraversal(BT -> Right);
    printf("%d ",BT -> Data);
}

// 二叉树的非递归遍历  
// 中序遍历的非递归算法实现  借助堆栈实现
struct SNode
{
    BinTree BT;
    struct SNode *Next;
};
typedef struct SNode *Stack;

Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(Stack));
    S -> Next = NULL;
    return S;
}

int IsEmpty(Stack S)
{
    if(S -> Next== NULL)
    {
        printf("堆栈空\n");
        return 1;
    }
    else return 0;
}

void Push(BinTree ID,Stack S)
{
    Stack Temp;
    Temp = (Stack)malloc(sizeof(Stack));
    Temp -> BT = ID;
    Temp -> Next = S -> Next;
    S -> Next = Temp;
    return; 
}

BinTree Pop(Stack S)
{
    Stack First;
    BinTree Q;
    if(IsEmpty(S))
    {
        printf("堆栈空");
        return NULL;
    }
    else
    {
        First = S -> Next;
        S -> Next = First -> Next;
        Q = First -> BT;
        free(First);
        return Q;
    }
}

void InOrderTraversal1(BinTree BT)
{
    BinTree T = BT;
    Stack S = CreateStack(); //创建并初始化堆栈
    while(T || !IsEmpty(S))
    {
        while(T) //一直向左将沿途节点压入堆栈
        {
            Push(T,S);
            T = T -> Left;
        } //一直当压入的左节点为NULL时出循环
        if(!IsEmpty(S)) //判断堆栈是否为空
        {
            T = Pop(S); //将不为空的节点出栈
            printf("%5d ",T -> Data); //输出节点数据
            T = T -> Right; //转向右子树
        }
    }
}

// ### 层序遍历  
// 队列实现:遍历从根结点开始，首先将根结点入队，然后开始执 行循环:结点出队、访问该结点、其左右儿子入队  
// 算法实现:
// void LevelOrderTraversal(BinTree BT)
// {
//     Queue Q;
//     BinTree T;
//     if(T!)
//         return;
//     Q = CreateQueue();
//     Add(BT,Q);
//     while(!IsEmpty(Q))
//     {
//         T = Delete(Q);
//         printf("%d\n",T -> Data);
//         if(T -> Left)
//             Add(T -> Left,Q);
//             Add(T -> Right,Q);
//     }
// }

//### 输出二叉树叶子节点  
void PreOrderPrintLeaves(BinTree BT)
{
    if(BT)
    {
        if(!BT -> Left && !BT -> Right)
            printf("%d\n",BT -> Data);
        PreOrderPrintLeaves(BT -> Right);
        PreOrderPrintLeaves(BT -> Left);
    }
}

int PostOrderGetHeight(BinTree BT)
{
    int HL,HR,MaxH;
    if(BT)
    {
        HL = PostOrderGetHeight(BT -> Left);
        HR = PostOrderGetHeight(BT -> Right);
        MaxH = (HL > HR)? HL : HR;
        return MaxH + 1;
    }
    else return 0;
}

int main(int argc,char *argv[])
{
    return 0;
}