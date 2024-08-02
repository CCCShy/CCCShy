
#include<stdio.h>
#include<stdlib.h>

#define MAXH 1001
#define MINH -100000

int H[MAXH], size;

void Create()
{
	H[0] = MINH;
	size = 0;
}

void Insert(int X)
{
	int i;
	for (i = ++size; X < H[i / 2]; i /= 2)
	{
		H[i] = H[i / 2];
	}
	H[i] = X;
}

int main()
{
	int n, m, i, X, j;
	scanf("%d %d", &n, &m);
	Create();
	for (i = 0; i < n; i++)
	{
		scanf("%d", &X);
		Insert(X);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &j);
		printf("%d ", H[j]);
		while (j > 1)
		{
			j /= 2;
			printf("%d ", H[j]);
		}
		puts("");
	}
	return 0;
}