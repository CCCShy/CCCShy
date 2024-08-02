#include<stdio.h>
#include<stdlib.h>
#define Number 12
typedef int ElementType;


//希尔排序
void Shell_Sort(ElementType A[], int N)
{
	int Si, D, P, i;
	int Sedgewick[] = { 929,505,209,109,41,19,5,1,0 };
	for (Si = 0; Sedgewick[Si] >= N; Si++);
	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
	{
		for (P = D; P < N; P++)
		{
			ElementType Tmp = A[P];
			for (i = P; i >= D && A[i - D] > Tmp; i -= D)
				A[i] = A[i - D];
			A[i] = Tmp;
		}
	}
}

int main()
{
	ElementType A[Number];
	int i;
	for (i = 0; i < Number; i++)
		scanf("%d", &A[i]);
	Shell_Sort(A, Number);
	for (i = 0; i < Number; i++)
		printf("%d ", A[i]);
	puts("");
	return 0;
}


//慕课代码：希尔排序-用Sedgewick增量序列
void ShellSort( ElementType A[], int N )
{ /* 希尔排序 - 用Sedgewick增量序列 */
     int Si, D, P, i;
     ElementType Tmp;
     /* 这里只列出一小部分增量 */
     int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
     
     for ( Si=0; Sedgewick[Si]>=N; Si++ ) 
         ; /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */

     for ( D=Sedgewick[Si]; D>0; D=Sedgewick[++Si] )
         for ( P=D; P<N; P++ ) { /* 插入排序*/
             Tmp = A[P];
             for ( i=P; i>=D && A[i-D]>Tmp; i-=D )
                 A[i] = A[i-D];
             A[i] = Tmp;
         }
}