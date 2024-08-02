#include<stdio.h>
#include<stdlib.h>

// # 队列 Queue  
// FIFO
// 操作集:长度为MaxSize的队列Q  Queue，队列元素item  ElementType
// 1. Queue CreatQueue( int MaxSize ):生成长度为MaxSize的空队列;
// 2. int IsFullQ( Queue Q, int MaxSize ):判断队列Q是否已满;
// 3. void AddQ( Queue Q, ElementType item ): 将数据元素item插入队列Q中; 
// 4. int IsEmptyQ( Queue Q ): 判断队列Q是否为空;
// 5. ElementType DeleteQ( Queue Q ):将队头数据元素从队列中删除并返回。  

// // ##  队列的顺序存储实现
// // 一个一维数组,队列头元素位置的变量front, 队列为元素位置的变量rear, 而堆栈由一个一位数组加上一个top.
// // 队列的结构
// // ```c
// #define MAXSIZE 10
// struct QNode
// {
//     int Data[MAXSIZE];
//     int front;
//     int rear;
// };
// typedef struct QNode *Queue;

// // 循环队列
// // 当front == rear时候, 空  
// // rear指向这个队列实际的最后一个元素的位置,front是第一个元素的前一个. 加入一个元素的时候rear + 1, 删除一个元素的时候front + 1  
// // 使用额外标记 size或者tag  
// // 仅使用n-1个数组空间  

// //创建队列   有问题！！！
// // Queue CreateQueue(int Maxsize)
// // {
// //     Queue Q = (Queue)malloc(sizeof(struct QNode));
// //     Q -> Data = (int)malloc(sizeof(Maxsize * sizeof(int)));
// //     Q -> front = Q -> rear = 0;
// //     Q -> Maxsize = Maxsize;
// // }

// // * 入队列
// // 用求余数函数,实现循环队列 例如 (5+1)%6 = 0, 放在第0位
// void AddQ(Queue Ptrl,int item)
// {
//     //判断队列是否满
//     if((Ptrl -> rear + 1) % MAXSIZE == Ptrl -> front)
//     {
//         printf("队列满\n");
//         return;
//     }
//     else
//     {
//         Ptrl -> rear = (Ptrl -> rear + 1) % MAXSIZE;
//         Ptrl -> Data[Ptrl -> rear] = item;
//     }
// }

// //出队列
// int DeleteQ(Queue Ptrl)
// {
//     //判断队列是否为空
//     if(Ptrl -> front == Ptrl -> rear)
//     {
//         printf("队列满\n");
//         return NULL;
//     }
//     else
//     {
//         Ptrl -> front = (Ptrl -> front + 1) % MAXSIZE;
//         return(Ptrl -> Data[Ptrl -> front]);
//     }
// }

// ##  队列的链式存储实现   
// 链表结点结构
struct Node
{
    int Data;
    struct Node *Next;
};
//链表队列结构
struct QNode
{
    struct Node *front;
    struct Node *rear;
};
typedef struct QNode *Queue;
Queue Ptrl;

//出队
int DeleteQ(Queue Ptrl)
{
    struct Node *FrontCell;
    int FrontElem;
    if(Ptrl -> front == NULL)
    {
        printf("队列空\n");
        return 0;
    }
    FrontCell = Ptrl -> front;
    if(Ptrl -> front == Ptrl -> rear)//队列仅剩一个元素时
    {
        Ptrl -> front = Ptrl -> rear = NULL;
    }
    else
    {
        Ptrl -> front = Ptrl -> front -> Next;
    }
        FrontElem = FrontCell -> Data;
        free(FrontCell);
        return FrontElem;
}

// ## 应用: 多项式加法运算  
// 算法思路:  
// 两个指针P1和P2分别指向这两个多项式第一个结点，不断循环:
// * P1->expon==P2->expon相同: 系数相加，若结果不为0，则作为结果多项式对应项
// 的系数。同时，P1和P2都分别指向下一项;
// * P1->expon>P2->expon 这时p1大: 将P1的当前项存入结果多项式，并使P1指向下一项;   
// * P1->expon<P2->expon 这时p2大: 将P2的当前项存入结果多项式，并使P2指向下一项;
// * 当某一多项式处理完时，将另一个多项式的所有结点依次复制到结果多项式中去。  

struct PloyNode
{
    int coef;//系数
    int expon;//指数
    struct PloyNode *link;//指向下一个节点的指针
};
typedef struct PloyNode *Polynomial;  //指向结构体的指针；
Polynomial P1,P2;

int Compare(int a,int b)
{
    return a > b ? 1 : (a == b ? 0 : -1);
}

void Attach(int c,int e,Polynomial *rear)
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PloyNode));
    P -> coef = c;
    P -> expon = e;
    P -> link = NULL;
    (*rear) -> link = P;
    (*rear) = P;
}

Polynomial PolyAdd(Polynomial P1,Polynomial P2)
{
    Polynomial front,rear,temp;
    int sum;
    rear = (Polynomial)malloc(sizeof(struct PloyNode));
    front = rear;
    while(P1 && P2)
    {
        switch(Compare(P1 -> expon,P2 -> expon))
        {
            case 1:
                Attach(P1 -> coef,P1 -> expon,&rear);
                P1 = P1 -> link;
                break;
            case -1:
                Attach(P2 -> coef,P2 -> expon,&rear);
                P2 = P2 -> link;
                break;
            case 0:
                sum = P1 -> coef + P2 -> coef;
                if(sum)
                    Attach(sum,P1 -> expon,&rear);
                P1 = P1 -> link;
                P2 = P2 -> link;
                break;
        }
    }
    for(;P1;P1 -> link)
        Attach(P1 -> coef,P1 -> expon,&rear);
    for(;P2;P2 -> link)
        Attach(P2 -> coef,P2 -> expon,&rear);
    rear -> link = NULL;
    temp = front;
    front = front -> link;
    free(temp);
    return front;
}

int main(int argc,char *argv[])
{
    return 0;
}







// // 慕课代码：队列的定义与操作-顺序存储
// typedef int Position;
// struct QNode {
//     ElementType *Data;     /* 存储元素的数组 */
//     Position Front, Rear;  /* 队列的头、尾指针 */
//     int MaxSize;           /* 队列最大容量 */
// };
// typedef struct QNode *Queue;

// Queue CreateQueue( int MaxSize )
// {
//     Queue Q = (Queue)malloc(sizeof(struct QNode));
//     Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
//     Q->Front = Q->Rear = 0;
//     Q->MaxSize = MaxSize;
//     return Q;
// }

// bool IsFull( Queue Q )
// {
//     return ((Q->Rear+1)%Q->MaxSize == Q->Front);
// }

// bool AddQ( Queue Q, ElementType X )
// {
//     if ( IsFull(Q) ) {
//         printf("队列满");
//         return false;
//     }
//     else {
//         Q->Rear = (Q->Rear+1)%Q->MaxSize;
//         Q->Data[Q->Rear] = X;
//         return true;
//     }
// }

// bool IsEmpty( Queue Q )
// {
//     return (Q->Front == Q->Rear);
// }

// ElementType DeleteQ( Queue Q )
// {
//     if ( IsEmpty(Q) ) { 
//         printf("队列空");
//         return ERROR;
//     }
//     else  {
//         Q->Front =(Q->Front+1)%Q->MaxSize;
//         return  Q->Data[Q->Front];
//     }
// }







// // 慕课代码：队列的定义与操作-链式存储
// typedef struct Node *PtrToNode;
// struct Node { /* 队列中的结点 */
//     ElementType Data;
//     PtrToNode Next;
// };
// typedef PtrToNode Position;

// struct QNode {
//     Position Front, Rear;  /* 队列的头、尾指针 */
//     int MaxSize;           /* 队列最大容量 */
// };
// typedef struct QNode *Queue;

// bool IsEmpty( Queue Q )
// {
//     return ( Q->Front == NULL);
// }

// ElementType DeleteQ( Queue Q )
// {
//     Position FrontCell; 
//     ElementType FrontElem;
    
//     if  ( IsEmpty(Q) ) {
//         printf("队列空");
//         return ERROR;
//     }
//     else {
//         FrontCell = Q->Front;
//         if ( Q->Front == Q->Rear ) /* 若队列只有一个元素 */
//             Q->Front = Q->Rear = NULL; /* 删除后队列置为空 */
//         else                     
//             Q->Front = Q->Front->Next;
//         FrontElem = FrontCell->Data;

//         free( FrontCell );  /* 释放被删除结点空间  */
//         return  FrontElem;
//     }
// }