#include<stdio.h>
#include<stdlib.h>

// // # 堆栈 Stack  
// // 具有一定操作约束的线性表，只在一端(栈顶，Top)做 插入、删除  
// // 操作集:长度为MaxSize的堆栈S 属于 Stack，堆栈元素item 属于 ElementType  
// // 1. Stack CreateStack( int MaxSize ): 生成空堆栈，其最大长度为MaxSize; 
// // 2. int IsFull( Stack S, int MaxSize ):判断堆栈S是否已满;
// // 3. void Push( Stack S, ElementType item ):将元素item压入堆栈;
// // 4. int IsEmpty ( Stack S ):判断堆栈S是否为空;
// // 5. ElementType Pop( Stack S ):删除并返回栈顶元素;

// #define MAXSIZE 10//存储数据堆栈的大小

// //堆栈
// //栈的顺序存储结构通常由一个一维数组和一个记录.栈顶元素位置的变量组成。
// typedef struct SNode *Stack;
// struct SNode
// {
//     int Data[MAXSIZE];//堆栈大小
//     int Top;//栈顶位置的数组下标
// };

// //1.判断堆栈是否满
// int IsFull(Stack PtrS)
// {
//     if(PtrS -> Top == MAXSIZE - 1)
//         return -1;
//     else return 0;
// }

// //2.入栈
// void Push(Stack PtrS,int X)
// {
//     if(PtrS -> Top == MAXSIZE - 1)
//     {
//         printf("堆栈满\n");
//         return;
//     }
//     else
//     {
//         PtrS -> Data[++PtrS -> Top] = X;
//     }
// }

// //3.出栈
// int Pop(Stack PtrS)
// {
//     if(PtrS -> Top == -1)
//     {
//         printf("堆栈空\n");
//         return -1;
//     }
//     else
//     {
//         return(PtrS -> Data[PtrS -> Top--]);

//     }
// }

// //  [例] 请用一个数组实现两个堆栈，要求最大地利用数组空间，使 数组只要有空间入栈操作就可以成功。  
// // 【分析】 一种比较聪明的方法是使这两个栈分别从数组的两头开始 向中间生长;当两个栈的栈顶指针相遇时，表示两个栈都满了。
// struct DStack
// {
//     int Data[MAXSIZE];
//     int Top1;
//     int Top2;
// }S;

// void Push1(struct DStack *PtrS,int X,int Tag)
// {
//     if(PtrS -> Top1 == PtrS -> Top2 - 1)
//     {
//         printf("堆栈满");
//         return;
//     }
//     if(Tag == 1)
//     {
//         return (PtrS -> Data[++PtrS -> Top1] = X);
//     }
//     else
//     {
//         return(PtrS -> Data[--PtrS -> Top2] = X);
//     }
// }

// int Pop1(struct DStack *PtrS,int Tag)
// {
//     if(Tag == 1)
//     {
//         if(PtrS -> Top1 == -1)
//         {
//             printf("堆栈1空\n");
//             return NULL;
//         }
//         else return(PtrS -> Data[PtrS -> Top1--]);
//     }
//     else
//     {
//         if(PtrS -> Top2 == MAXSIZE - 1)
//         {
//             printf("堆栈2空\n");
//             return NULL;
//         }
//         else return(PtrS -> Data[PtrS -> Top2++]);
//     }
// }


// int main(int argc,char *argv[])
// {   
//     S.Top1 = -1;
//     S.Top2 = MAXSIZE;
//     return 0;
// }

typedef struct SNode *Stack;
struct SNode
{
    int Data;
    struct SNode *Next;
};

//初始化（建立空栈）
Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S -> Next = NULL;
    return S;
}

//判断栈是否为空
int IsEmpty(Stack S)
{
    if(S -> Next == NULL)
    {
        printf("堆栈为空\n");
        return 1;
    }
    return 0;
}

//入栈(插入和删除均在栈顶进行)
void Push(int item,Stack S)
{
    struct SNode *Temp;
    Temp = (Stack)malloc(sizeof(struct SNode));
    Temp -> Data = item;
    Temp -> Next = S -> Next;
    S -> Next = Temp;
    return;
}

int Pop(Stack S)
{
    struct SNode *FirstCell;
    int TopElem;
    //先判断堆栈是否为空
    if(IsEmpty(S))
    {
        printf("堆栈空\n");
        return NULL;
    }
    else
    //堆栈不空开始出栈操作
    {
        FirstCell = S -> Next;
        S -> Next = FirstCell -> Next;
        TopElem = FirstCell -> Data;
        free(FirstCell);
        return TopElem;
    }
}

int main(int argc,char *argv[])
{   
    return 0;
}







// 慕课代码：堆栈的定义与操作-顺序存储
typedef int Position;
struct SNode {
    ElementType *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool IsFull( Stack S )
{
    return (S->Top == S->MaxSize-1);
}

bool Push( Stack S, ElementType X )
{
    if ( IsFull(S) ) {
        printf("堆栈满");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty( Stack S )
{
    return (S->Top == -1);
}

ElementType Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("堆栈空");
        return ERROR; /* ERROR是ElementType的特殊值，标志错误 */
    }
    else 
        return ( S->Data[(S->Top)--] );
}




// 慕课代码：堆栈的定义与操作-链式存储
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack( ) 
{ /* 构建一个堆栈的头结点，返回该结点指针 */
    Stack S;

    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty ( Stack S )
{ /* 判断堆栈S是否为空，若是返回true；否则返回false */
    return ( S->Next == NULL );
}

bool Push( Stack S, ElementType X )
{ /* 将元素X压入堆栈S */
    PtrToSNode TmpCell;

    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}

ElementType Pop( Stack S )  
{ /* 删除并返回堆栈S的栈顶元素 */
    PtrToSNode FirstCell;
    ElementType TopElem;

    if( IsEmpty(S) ) {
        printf("堆栈空"); 
        return ERROR;
    }
    else {
        FirstCell = S->Next; 
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}