#include<stdio.h>
#include<math.h>
#include<time.h>

// # 基本概念
// * 空间使用  
// 函数PrintN，使得传入一个正整数为N的参数后，打印从1到N的全部正整数。
//方法一：循环实现
void PrintN1(int N)//循环实现
{
    int i = 1;
    for(i = 1;i <= N;i++)
    {
        printf("%d ",i);
    }
    return;
}

//方法二：递归实现
void PrintN2(int N)//递归实现
{
    if(N)
    {
        PrintN2(N-1);
        printf("%d ",N);
    }
    return;
}


// * 算法效率
// 多项式 f(x) = a0 + a1*x^1 +... +an * x^n
//方法一
// double f1(int n,double a[],double x)
// {
//     int i = 0;
//     double p = a[0];
//     for(i = 1;i <= n;i++)
//     {
//         p += (a[i] * pow(x,i));
//     }
//     return p;
// }

// //方法二
// double f2(int n,double a[],double x)
// {
//     int i;
//     double p = a[n];
//     for(i = n;i > 0;i--)
//     {
//         p = a[i-1] + p*x;
//     }
//     return p;
// }

// 计时  
// CLK_TCK 为常数，机器始终每秒所走的打点数 Use CLOCKS_PER_SEC instead of CLK_TCK on mac  
// #include <time.h>
// clock_t start,stop; //定义两个常量start和stop，用来计算函数运行时间
// double duration;   
// #define MAXN 10  //多项式最大项数 0~9项
// #define MAXK 1e7 //被测函数最大重复调用次数
// int main(int argc, char *argv[])
// {
//     int i = 0;
//     double a[MAXN];
//     for(i = 0;i < MAXN;i++)
//         a[i] = (double)i;
    
//     start = clock();
//     for(i = 0;i < MAXK;i++)//重复调用函数以获得充分多的时钟打点数
//         f1(MAXN - 1, a, 1.1);
//     stop = clock();
//     duration = ((double)(stop - start))/CLK_TCK/MAXK;//计算函数单词执行时间
//     printf("ticks1 = %f\n",(double)(stop - start));
//     printf("duration1 = %6.2e\n",duration);

//     start = clock();
//     for(i = 0;i < MAXK;i++)
//         f2(MAXN - 1, a, 1.1);
//     stop = clock();
//     duration = ((double)(stop - start))/CLK_TCK/MAXK;
//     printf("ticks2 = %f\n",(double)(stop - start));
//     printf("duration2 = %6.2e\n",duration);
//     return 0;
// }

// //讨论 1/i多项式
// #include<math.h>
// #include<time.h>
// double f1(int n, double a[], double x)
// {
// 	int i = 0;
// 	double p = a[0];
// 	for (i = 1; i < n; i++)
// 		p += a[i] * pow(x, i);
// 	return p;
// }

// double f2(int n, double a[], double x)
// {
// 	int i = 0;
// 	double p = a[n];
// 	for (int i = n; i > 0; i--)
// 		p = a[i - 1] + p * x;
// 	return p;
// }

// clock_t start, stop;
// double duration;
// #define MAXN 100
// #define MAXK 1e5
// int main()
// {
// 	int i = 0;
// 	double a[MAXN] = { 1 };
// 	for (i = 1; i < MAXN; i++)
// 	{
// 		a[i] = (double)(1 / i);
// 	}
// 	 start = clock();
// 	 for (i = 0; i < MAXK; i++)
// 	 {
// 		 f1(MAXN, a, 1.1);
// 	 }
// 	 stop = clock();
// 	 duration = ((double)(stop - start)) / CLK_TCK/MAXK;
// 	 printf("ticks1 = %f\n", (double)(stop - start));
// 	 printf("duration1 = %6.2e\n",duration);

// 	 start = clock();
// 	 for (i = 0; i < MAXK; i++)
// 	 {
// 		 f2(MAXN, a, 1.1);
// 	 }
// 	 stop = clock();
// 	 duration = ((double)(stop - start)) / CLK_TCK/MAXK;
// 	 printf("ticks1 = %f\n", (double)(stop - start));
// 	 printf("duration1 = %6.2e\n", duration);
// 	return 0;
// }

// # 实例： 最大子列和问题
//算法一：     T(N) =  O(N^3)  
int MaxSubseqSum1(int A[],int N)//暴力算法 时间复杂度T(n) = O(n³) 
{
    int ThisSum,MaxSum;
    int i,j,k;
    for(i = 0;i < N;i++)
    {
        for(j = i;j < N;j++)
        {
            ThisSum = 0;
            for(k = i;k < j;k++)
                ThisSum += A[k];
            if(ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

//算法二：     T(N) =  O(N^2)  
int MaxSubseqSum2(int A[],int N)
{
    int ThisSum,MaxSum;
    int i,j;
    for(i = 0;i < N;i++)
    {
        ThisSum = 0;
        for(j = i;j < N;j++)
        {
            ThisSum += A[j];
            if(ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

//算法三：   分而治之       T(N) = O(NlogN)


//算法四： 在线处理         T(N) = O(N)
int MaxSubseqSum4(int A[],int N)
{
    int ThisSum,MaxSum,i;
    ThisSum = MaxSum = 0;
    for(i = 0;i < N;i++)
    {
        ThisSum += A[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

// clock_t start,stop;
// double duration;
// #define MAXN 10000
// int main(int argc, char *argv[])
// {
//     int i = 0;
//     int A[MAXN];
//     for(i = 0;i < MAXN;i++)
//         A[i] = i;
    
//     start = clock();
//     MaxSubseqSum1(A,MAXN);
//     stop = clock();
//     duration = ((double)(stop - start))/CLK_TCK;
//     printf("ticks1 = %f\n",(double)(stop - start));
//     printf("duration1 = %6.2e\n",duration);

//     // start = clock();
//     // MaxSubseqSum2(A,MAXN);
//     // stop = clock();
//     // duration = ((double)(stop - start))/CLK_TCK;
//     // printf("ticks1 = %f\n",(double)(stop - start));
//     // printf("duration1 = %6.2e\n",duration);
    
//     // start = clock();
//     // MaxSubseqSum4(A,MAXN);
//     // stop = clock();
//     // duration = ((double)(stop - start))/CLK_TCK;
//     // printf("ticks1 = %f\n",(double)(stop - start));
//     // printf("duration1 = %6.2e\n",duration);
//     return 0;
// }


//分而治之思想
// int Max3( int A, int B, int C )
// { /* 返回3个整数中的最大值 */
//     return A > B ? A > C ? A : C : B > C ? B : C;
// }

// int DivideAndConquer( int List[], int left, int right )
// { /* 分治法求List[left]到List[right]的最大子列和 */
//     int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
//     int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/

//     int LeftBorderSum, RightBorderSum;
//     int center, i;

//     if( left == right )  { /* 递归的终止条件，子列只有1个数字 */
//         if( List[left] > 0 )  return List[left];
//         else return 0;
//     }

//     /* 下面是"分"的过程 */
//     center = ( left + right ) / 2; /* 找到中分点 */
//     /* 递归求得两边子列的最大和 */
//     MaxLeftSum = DivideAndConquer( List, left, center );
//     MaxRightSum = DivideAndConquer( List, center+1, right );

//     /* 下面求跨分界线的最大子列和 */
//     MaxLeftBorderSum = 0; LeftBorderSum = 0;
//     for( i=center; i>=left; i-- ) { /* 从中线向左扫描 */
//         LeftBorderSum += List[i];
//         if( LeftBorderSum > MaxLeftBorderSum )
//             MaxLeftBorderSum = LeftBorderSum;
//     } /* 左边扫描结束 */

//     MaxRightBorderSum = 0; RightBorderSum = 0;
//     for( i=center+1; i<=right; i++ ) { /* 从中线向右扫描 */
//         RightBorderSum += List[i];
//         if( RightBorderSum > MaxRightBorderSum )
//             MaxRightBorderSum = RightBorderSum;
//     } /* 右边扫描结束 */

//     /* 下面返回"治"的结果 */
//     return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
// }

// int MaxSubseqSum3( int List[], int N )
// { /* 保持与前2种算法相同的函数接口 */
//     return DivideAndConquer( List, 0, N-1 );
// }