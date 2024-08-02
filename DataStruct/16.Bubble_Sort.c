#include<stdio.h>
#include<stdlib.h>
#define Number 5
typedef int ElementType;


//函数统一格式：void X_Sort(ELementType A[], int N)
//N：要排元素个数
//默认从小到大排序


void Swap(ElementType* a, ElementType* b)
{
	ElementType c;
	c = *a;
	*a = *b;
	*b = c;
}

//冒泡排序
void Bubble_Sort(ElementType A[], int N)
{
	int i, p;
	int flag;
	for (p = N-1; p >= 0; p--)
	{
		flag = 0;
		for (i = 0; i < p; i++)
		{
			if (A[i] > A[i + 1])
			{
				Swap(&A[i], &A[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

int main()
{
	ElementType A[Number];
	int i;
	for (i = 0; i < Number; i++)
		scanf("%d", &A[i]);
	Bubble_Sort(A, Number);
	for (i = 0; i < Number; i++)
		printf("%d ", A[i]);
	puts("");
	return 0;
}