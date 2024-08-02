#include<stdio.h>
#include<stdlib.h>

//# 线性结构

/* ## 线性表 Linear List
同类型数据元素构成有序序列的线性结构。  
数据对象集：n个元素构成的有序序列  
操作集：线性表L属于List, 整数表示位置，元素x属于ElementType。操作：
* List MakeEmpty(): 初始化一个空表
* ElementType FindKth(int K, List L); 根据位序K，返回相应元素
* int Find(ElementType x, List L);  在表中查找X第一次出现的位置
* void insert(ElementType X, int i, List L); 插入
* void Delete(int i, List l);  删除  
* int length(List L); 返回长度  */

/*## 线性存储序列的实现 
```c
typedef struct LNode *List; 
struct LNode{
   ElementType Data[MAXSIZE];
   int Last; 
};
struct LNode L; 
List PtrL;
```
访问元素：L.Data[i] or PtrL->Data[i]  
线性表的长度:L.Last+1 或 PtrL->Last+1  (last代表位置，因为从零开始所以是n-1) */
// #define MAXSIZE 10
// typedef struct LNode *List;
// struct LNode
// {  
//     int a[MAXSIZE];
//     int Last;
// };
// struct LNode L;
// List Ptrl;

// //1.初始化
// List MakeEmpty()
// {
//     List Ptrl;
//     Ptrl = (List)malloc(sizeof(struct LNode));
//     Ptrl -> Last = -1;
//     return Ptrl;
// }

// //2.查找为线性表Ptrl中X第一次出现的位置
// int FindKth(int X, List Ptrl)
// {
//     int i = 0;
//     while(i <= Ptrl -> Last && X != Ptrl -> a[i])
//     {
//         i++;
//     }
//     if(i > Ptrl -> Last)
//         return -1;
//     else return i;
// }

// //3.插入操作实现
// void Insert(int X,int i,List Ptrl)
// {
//     int j;
//     if(Ptrl -> Last = MAXSIZE - 1)
//     {
//         printf("表满\n");
//         return;
//     }
//     if(i < 1 || i > Ptrl -> Last+2)
//     {
//         printf("插入位置不合法\n");
//         return;
//     }
//     for(j = Ptrl -> Last;j >= i-1;j--)
//     {
//         Ptrl -> a[j+1] = Ptrl -> a[j]; 
//     }
//     Ptrl -> a[i] = X;
//     Ptrl -> Last++;
//     return;
// }

// //4.删除操作
// void Delete(int i,List Ptrl)
// {
//     int j;//用来遍历数组
//     if(Ptrl -> Last == -1) //判断表是否空 Last为最后元素的数组下标
//     {
//         printf("表空\n");
//         return;
//     }
//     if(i < 1 || i > Ptrl -> Last + 1) //判断删除位置是否合法
//     {
//         printf("不存在第%d个元素\n",i);
//         return;
//     }
//     for(j = i;j <= Ptrl -> Last;j++) 
//     {
//         Ptrl -> a[j-1] = Ptrl -> a[j];
//     }
//     Ptrl -> Last--; //使Last仍为最后元素的下标
//     return;
// }

//线性表链式存储的视线
typedef struct LNode *List; 
struct LNode
{
    int Data;
    List Next;
};
struct LNode L;
List Ptrl;

//1.求表长
int Length(List Ptrl)
{
    List p = Ptrl;
    int j = 0;
    while(p)
    {
        p = p -> Next;
        j++;
    }
    return j;
}

//2.按位序查找：FindKth
List FindeKth(int K,List Ptrl)
{
    int i;
    List p = Ptrl;
    for(i = 1;p != NULL && i < K;i++)
    {
        p = p -> Next;
    }
    if(i == K)
    return p;
    else return NULL;
}

//按值查找
List Find(int X,List Ptrl)
{
    List p = Ptrl;
    while(p -> Data != X && p!= NULL)
    {
        p = p ->Next;
    }
    return p;
}

//3.插入
List Insert(int X,int i,List Ptrl)
{
    List p,s;
    p = Ptrl;
    s = (List)malloc(sizeof(struct LNode));
    if(i == 1)
    {
        s -> Data = X;
        s -> Next = Ptrl;
        return s;
    }
    p = FindKth(i-1,Ptrl);
    if(p == NULL)
    {
        printf("参数i错\n");
        return NULL;
    }
    else
    {
        s -> Data = X;
        s -> Next = p -> Next;
        p -> Next = s;
        return Ptrl;
    }
}

//4.删除
List Delete(int i,List Ptrl)
{
    List s,p;
    if(i == 1)
    {
        s = Ptrl;
        if(Ptrl != NULL)
        {
            Ptrl = Ptrl ->Next;
        }
        else
        return NULL;
        free(s);
        return Ptrl;
    }
    p = FindKth(i-1,Ptrl);
    if(p == NULL)
    {
        printf("第%d节点不存在\n",i-1);
        return NULL;
    }
    else if(p -> Next == NULL)
    {
        printf("第%d节点不存在\n",i);
    }
    else
    {
        s = p -> Next;
        p -> Next = s -> Next;
        free(s);
        return Ptrl;
    }
}

int main(int argc,char *argv[])
{
    return 0;
}


//慕课代码：线性表的定义-顺序表
// typedef int Position;
// typedef struct LNode *List;
// struct LNode {
//     ElementType Data[MAXSIZE];
//     Position Last;
// };

// /* 初始化 */
// List MakeEmpty()
// {
//     List L;

//     L = (List)malloc(sizeof(struct LNode));
//     L->Last = -1;

//     return L;
// }

// /* 查找 */
// #define ERROR -1

// Position Find( List L, ElementType X )
// {
//     Position i = 0;

//     while( i <= L->Last && L->Data[i]!= X )
//         i++;
//     if ( i > L->Last )  return ERROR; /* 如果没找到，返回错误信息 */
//     else  return i;  /* 找到后返回的是存储位置 */
// }

// /* 插入 */
// /*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
// bool Insert( List L, ElementType X, Position P ) 
// { /* 在L的指定位置P前插入一个新元素X */
//     Position i;

//     if ( L->Last == MAXSIZE-1) {
//         /* 表空间已满，不能插入 */
//         printf("表满"); 
//         return false; 
//     }  
//     if ( P<0 || P>L->Last+1 ) { /* 检查插入位置的合法性 */
//         printf("位置不合法");
//         return false; 
//     } 
//     for( i=L->Last; i>=P; i-- )
//         L->Data[i+1] = L->Data[i]; /* 将位置P及以后的元素顺序向后移动 */
//     L->Data[P] = X;  /* 新元素插入 */
//     L->Last++;       /* Last仍指向最后元素 */
//     return true; 
// } 

// /* 删除 */
// /*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
// bool Delete( List L, Position P )
// { /* 从L中删除指定位置P的元素 */
//     Position i;

//     if( P<0 || P>L->Last ) { /* 检查空表及删除位置的合法性 */
//         printf("位置%d不存在元素", P ); 
//         return false; 
//     }
//     for( i=P+1; i<=L->Last; i++ )
//         L->Data[i-1] = L->Data[i]; /* 将位置P+1及以后的元素顺序向前移动 */
//     L->Last--; /* Last仍指向最后元素 */
//     return true;   
// }


// 慕课代码：线性表的定义-链式表
// typedef struct LNode *PtrToLNode;
// struct LNode {
//     ElementType Data;
//     PtrToLNode Next;
// };
// typedef PtrToLNode Position;
// typedef PtrToLNode List;

// /* 查找 */
// #define ERROR NULL

// Position Find( List L, ElementType X )
// {
//     Position p = L; /* p指向L的第1个结点 */

//     while ( p && p->Data!=X )
//         p = p->Next;

//     /* 下列语句可以用 return p; 替换 */
//     if ( p )
//         return p;
//     else
//         return ERROR;
// }

// /* 带头结点的插入 */
// /*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是链表结点指针，在P之前插入新结点 */
// bool Insert( List L, ElementType X, Position P )
// { /* 这里默认L有头结点 */
//     Position tmp, pre;

//     /* 查找P的前一个结点 */        
//     for ( pre=L; pre&&pre->Next!=P; pre=pre->Next ) ;            
//     if ( pre==NULL ) { /* P所指的结点不在L中 */
//         printf("插入位置参数错误\n");
//         return false;
//     }
//     else { /* 找到了P的前一个结点pre */
//         /* 在P前插入新结点 */
//         tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
//         tmp->Data = X; 
//         tmp->Next = P;
//         pre->Next = tmp;
//         return true;
//     }
// }

// /* 带头结点的删除 */
// /*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是拟删除结点指针 */
// bool Delete( List L, Position P )
// { /* 这里默认L有头结点 */
//     Position pre;

//     /* 查找P的前一个结点 */        
//     for ( pre=L; pre&&pre->Next!=P; pre=pre->Next ) ;            
//     if ( pre==NULL || P==NULL) { /* P所指的结点不在L中 */
//         printf("删除位置参数错误\n");
//         return false;
//     }
//     else { /* 找到了P的前一个结点pre */
//         /* 将P位置的结点删除 */
//         pre->Next = P->Next;
//         free(P);
//         return true;
//     }
// }