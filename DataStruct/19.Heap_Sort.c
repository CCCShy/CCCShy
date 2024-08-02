#include<stdio.h>
#include<stdlib.h>
#define Number 12
typedef int ElementType;

//堆排序
void PercDown(ElementType A[], int p, int N)
{
	int Parent, Child;
	ElementType X;
	X = A[p];
	for (Parent = p; 2 * Parent < N; Parent = Child)
	{
		Child = 2 * Parent;
		if ((Child != N - 1) && (A[Child] < A[Child + 1]))
			Child++;
		if (X >= A[Child])
			break;
		else
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

void Heap_Sort(ElementType A[], int N)
{
	int i;
	for (i = N / 2; i >= 0; i--)//BuildMaxHeap建立最大堆
		PercDown(A, i, N);
	for (i = N - 1; i > 0; i--)//删除最大堆顶
	{
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}

int main()
{
	ElementType A[Number];
	int i;
	for (i = 0; i < Number; i++)
		scanf("%d", &A[i]);
	Heap_Sort(A, Number);
	for (i = 0; i < Number; i++)
		printf("%d ", A[i]);
	puts("");
	return 0;
}




//慕课代码：堆排序
void Swap( ElementType *a, ElementType *b )
{
     ElementType t = *a; *a = *b; *b = t;
}
 
void PercDown1( ElementType A[], int p, int N )
{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
  /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;

    X = A[p]; /* 取出根结点存放的值 */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= A[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}

void HeapSort( ElementType A[], int N ) 
{ /* 堆排序 */
     int i;
      
     for ( i=N/2-1; i>=0; i-- )/* 建立最大堆 */
         PercDown( A, i, N );
     
     for ( i=N-1; i>0; i-- ) {
         /* 删除最大堆顶 */
         Swap( &A[0], &A[i] ); /* 见代码7.1 */
         PercDown( A, 0, i );
     }
}