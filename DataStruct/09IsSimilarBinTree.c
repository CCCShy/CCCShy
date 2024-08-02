#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;

typedef struct TreeNode* Tree;
struct TreeNode
{
	ElementType Data;
	Tree Left, Right;
	int flag;//是否被访问过的标记，是为1，否为0
};

Tree MakeTree(int N);
int Judge(Tree T, int N);
void Reset(Tree T);
Tree NewNode(ElementType X);
Tree Insert(Tree T, ElementType X);
void FreeTree(Tree T);
int Check(Tree T, ElementType X);


int main()
{
	int N, L, i;
	Tree T;
	scanf("%d", &N);
	while (N)
	{
		scanf("%d", &L);
		T = MakeTree(N);
		for (i = 0; i < L; i++)
		{
			if (Judge(T, N))
				printf("Yes\n");
			else
				printf("No\n");
			Reset(T);
		}
		FreeTree(T);	
		scanf("%d", &N);
	}
	return 0;
}

Tree MakeTree(int N)
{
	Tree T;
	ElementType X;
	scanf("%d", &X);
	T = NewNode(X);
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &X);
		T = Insert(T, X);
	}
	return T;
}

Tree NewNode(ElementType X)
{
	Tree T;
	T = (Tree)malloc(sizeof(struct TreeNode));
	T->Data = X;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}

Tree Insert(Tree T, ElementType X)
{
	if (!T)
		T = NewNode(X);
	else
	{
		if (X > T->Data)
			T->Right = Insert(T->Right, X);
		else if (X < T->Data)
			T->Left = Insert(T->Left, X);
		else
			printf("已有相同元素\n");
	}
	return T;
}



int Judge(Tree T, int N)
{
	int flag = 1;
	ElementType X;
	scanf("%d", &X);
	if (X != T->Data)
		flag = 0;
	else
		T->flag = 1;
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &X);
		if (!Check(T, X))
			flag = 0;
	}
	return flag;
}

int Check(Tree T, ElementType X)
{
	if (T->flag)
	{
		if (X < T->Data)
			return Check(T->Left, X);
		else if (X > T->Data)
			return Check(T->Right, X);
		else
			return 0;
	}
	else
	{
		if (X == T->Data)
		{
			T->flag = 1;
			return 1;
		}
		else return 0;
	}
}

void Reset(Tree T)
{
	if (T->Left)
		Reset(T->Left);
	if (T->Right)
		Reset(T->Right);
	T->flag = 0;
}

void FreeTree(Tree T)
{
	if (T->Left)
		FreeTree(T->Left);
	if (T->Right)
		FreeTree(T->Right);
	free(T);
}