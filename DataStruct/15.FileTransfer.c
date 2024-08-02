
//#include<stdio.h>
//#include<stdlib.h>
//#define MaxSize 1000
//
//typedef int ElementType;
//typedef ElementType SetType[MaxSize];
//
//void Initialization(SetType S,int n)
//{
//	for (int i = 0; i < n; i++)
//		S[i] = -1;
//}
//
//int Find(SetType S,ElementType X)
//{
//	for (; S[X] >= 0; X = S[X]);
//	return X;
//}
//
//void Union(SetType S, ElementType Root1, ElementType Root2)
//{
//	if (S[Root2] < S[Root1])
//	{
//		S[Root2] += S[Root1];
//		S[Root1] = Root2;
//	}
//	else
//	{
//		S[Root1] += S[Root2];
//		S[Root2] = Root1;
//	}
//}
//
//void Check_connection(SetType S)
//{
//	ElementType u, v;
//	scanf("%d %d", &u, &v);
//	if (Find(S, u) != Find(S, v))
//		printf("no\n");
//	else
//		printf("yes\n");
//}
//
//void Input_connection(SetType S)
//{
//	ElementType u, v;
//	int Root1, Root2;
//	scanf("%d %d", &u, &v);
//	Root1 = Find(S, u);
//	Root2 = Find(S, v);
//	if (Root1 != Root2)
//		Union(S, Root1, Root2);
//}
//
//void Check_network(SetType S, int n)
//{
//	int i;
//	int count = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (S[i] < 0)
//			count++;
//	}
//	if (count == 1)
//		printf("The network is successfully connected.\n");
//	else
//		printf("There are %d components.\n",count);
//}
//
//int main()
//{
//	SetType S;
//	int n;
//	char in;
//	scanf("%d", &n);
//	Initialization(S, n);
//	do
//	{
//		scanf("%c", &in);
//		switch (in)
//		{
//		case 'C':
//			Check_connection(S);
//			break;
//		case 'I':
//			Input_connection(S);
//			break;
//		case 'S':
//			Check_network(S, n);
//			break;
//		}
//	} while (in != 'S');
//	return 0;
//}