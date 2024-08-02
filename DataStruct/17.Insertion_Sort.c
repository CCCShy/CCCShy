#include<stdio.h>
#include<stdlib.h>
#define Number 5
typedef int ElementType;

//插入排序
void Insertion_Sort(ElementType A[], int N)
{
	int i, p;
	for (p = 1; p < N; p++)
	{
		ElementType tmp = A[p];
		for (i = p; i > 0 && A[i - 1] > tmp; i--)
			A[i] = A[i - 1];
		A[i] = tmp;
	}
}

int main()
{
	ElementType A[Number];
	int i;
	for (i = 0; i < Number; i++)
		scanf("%d", &A[i]);
	Insertion_Sort(A, Number);
	for (i = 0; i < Number; i++)
		printf("%d ", A[i]);
	puts("");
	return 0;
}

//慕课代码：插入排序
void InsertionSort( ElementType A[], int N )
{ /* 插入排序 */
     int P, i;
     ElementType Tmp;
     
     for ( P=1; P<N; P++ ) {
         Tmp = A[P]; /* 取出未排序序列中的第一个元素*/
         for ( i=P; i>0 && A[i-1]>Tmp; i-- )
             A[i] = A[i-1]; /*依次与已排序序列中元素比较并右移*/
         A[i] = Tmp; /* 放进合适的位置 */
     }
}