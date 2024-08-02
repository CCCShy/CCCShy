#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#define Number 12
typedef int ElementType;


//归并排序
//递归算法
void Merge1(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd, Tmp;
	LeftEnd = R - 1;
	Tmp = L;
	int ElementNum = RightEnd - L + 1;
	while(L <= LeftEnd&& R <= RightEnd)
	{
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}
	while(L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];
	for (int i = 0; i < ElementNum; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}

void MSort1(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{
	int Center;
	if (L < RightEnd)
	{
		Center = (RightEnd + L) / 2;
		MSort1(A, TmpA, L, Center);
		MSort1(A, TmpA, Center + 1, RightEnd);
		Merge1(A, TmpA, L, Center + 1, RightEnd);
	}
}

void Merge_Sort1(ElementType A[],int N)
{
	ElementType* TmpA;
	TmpA = (ElementType*)malloc(N * sizeof(ElementType));
	if (TmpA != NULL)
	{
		MSort1(A, TmpA, 0, N - 1);
		free(TmpA);
	}
	else
		printf("Error:空间不足\n");
}

//非递归算法
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd, Tmp;
	LeftEnd = R - 1;
	Tmp = L;
	while (L <= LeftEnd && R <= RightEnd)
	{
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}
	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];
}

void Merge_Pass(ElementType A[], ElementType TmpA[], int N, int length)
{
	int i;
	for (i = 0; i <= N - 2 * length; i += 2 * length)
		Merge(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < N)
		Merge(A, TmpA, i, i + length, N - 1);
	else
		for (int j = i; j < N; j++)
			TmpA[j] = A[j];
}

void Merge_Sort2(ElementType A[], int N)
{
	int length = 1;
	ElementType* TmpA = (ElementType*)malloc(N * sizeof(ElementType));
	if (TmpA != NULL)
	{
		while (length < N)
		{
			Merge_Pass(A, TmpA, N, length);
			length *= 2;
			Merge_Pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
	else
		printf("Error:空间不足\n");
}



int main()
{
	ElementType A[Number];
	int i;
	for (i = 0; i < Number; i++)
		scanf("%d", &A[i]);
	Merge_Sort2(A, Number);
	for (i = 0; i < Number; i++)
		printf("%d ", A[i]);
	puts("");
	return 0;
}



//慕课代码：归并排序
/* 归并排序 - 递归实现 */

/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
     int LeftEnd, NumElements, Tmp;
     int i;
     
     LeftEnd = R - 1; /* 左边终点位置 */
     Tmp = L;         /* 有序序列的起始位置 */
     NumElements = RightEnd - L + 1;
     
     while( L <= LeftEnd && R <= RightEnd ) {
         if ( A[L] <= A[R] )
             TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
         else
             TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
     }

     while( L <= LeftEnd )
         TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
     while( R <= RightEnd )
         TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */
         
     for( i = 0; i < NumElements; i++, RightEnd -- )
         A[RightEnd] = TmpA[RightEnd]; /* 将有序的TmpA[]复制回A[] */
}

void Msort( ElementType A[], ElementType TmpA[], int L, int RightEnd )
{ /* 核心递归排序函数 */ 
     int Center;
     
     if ( L < RightEnd ) {
          Center = (L+RightEnd) / 2;
          Msort( A, TmpA, L, Center );              /* 递归解决左边 */ 
          Msort( A, TmpA, Center+1, RightEnd );     /* 递归解决右边 */  
          Merge( A, TmpA, L, Center+1, RightEnd );  /* 合并两段有序序列 */ 
     }
}

void MergeSort( ElementType A[], int N )
{ /* 归并排序 */
     ElementType *TmpA;
     TmpA = (ElementType *)malloc(N*sizeof(ElementType));
     
     if ( TmpA != NULL ) {
          Msort( A, TmpA, 0, N-1 );
          free( TmpA );
     }
     else printf( "空间不足" );
}

/* 归并排序 - 循环实现 */
/* 这里Merge函数在递归版本中给出 */

/* length = 当前有序子列的长度*/
void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length )
{ /* 两两归并相邻有序子列 */
     int i, j;
      
     for ( i=0; i <= N-2*length; i += 2*length )
         Merge( A, TmpA, i, i+length, i+2*length-1 );
     if ( i+length < N ) /* 归并最后2个子列*/
         Merge( A, TmpA, i, i+length, N-1);
     else /* 最后只剩1个子列*/
         for ( j = i; j < N; j++ ) TmpA[j] = A[j];
}

void Merge_Sort( ElementType A[], int N )
{ 
     int length; 
     ElementType *TmpA;
     
     length = 1; /* 初始化子序列长度*/
     TmpA = malloc( N * sizeof( ElementType ) );
     if ( TmpA != NULL ) {
          while( length < N ) {
              Merge_pass( A, TmpA, N, length );
              length *= 2;
              Merge_pass( TmpA, A, N, length );
              length *= 2;
          }
          free( TmpA );
     }
     else printf( "空间不足" );
}