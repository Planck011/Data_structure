#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Structure.h"
#include"FindandSort.h"
void ListQ();
void TreeQ();
void StackandQunen();
void GraphQ();
void FindSort();
void menu(elem arr[]);
void jiecheng(int n,int a[])
{
	int i, j,k;
	int c = 0;
	for (i = 2; i <= n; i++)
	{
		for (j = 0; j < 100; j++)
		{
			k = a[j] * i + c;
			a[j] = k % 10;
			c = k / 10;
		}
	}
}
int findm(int a[])
{
	int m;
	for (m = 99; m >= 0; m--)
	{
		if (a[m] != 0)
			break;
	}
	return m;
}
void deal(int a[],int num,int s)
{
	int i, j;
	int count = 0;
	if (s % 4 != 0)
	{
		printf("no\n");
		return;
	}
	int e = s / 4;
	bool flag[25];
	memset(flag, false, sizeof(flag));
	for (i = 0; i < num; i++)
	{
		if (!flag[i])
		{
			for (j = i + 1; j < num; j++)
			{
				if (a[i] + a[j] == e && !flag[j])
				{
					flag[i] = true;
					flag[j] = true;
					count++;
				}
			}
		}
		
	}
}
int cmp(const void *a, const void *b)
{
	return (int*)b - (int*)a;
}
int main()
{
	//FindSort();
	//int a[8] = { 0 };//0x0113F700-0x0113F71C
	elem a[MAX];
	for (int i = 0; i < MAX; i++)
	{
		scanf_s("%d", a[i]->key);
		
	}
	int kk, i, j;
	for (i = 1; i<MAX; i++)
	{
		if (a[i]->key<a[i - 1]->key)
		{
			kk = a[i]->key;
			for (j = i - 1; kk<a[j - 1]->key && j >= 0; j--)
				a[j + 1]->key = a[j]->key;
			a[j + 1]->key = kk;
		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	//menu(a);
	//int continue1 = 1;//0x0113F728
	system("pause");
	return 0;
}
void menu(elem arr[])
{
	printf("*******************************************************\n");
	printf("请选择(按0退出）\n1.插入排序\t2.折半排序\t3.希尔排序\n4.冒泡排序\t5.快速排序\t6.选择排序\n7.堆 排序\t8.归并排序\n");
	int ch;
	scanf_s("%d", &ch);
	switch (ch)
	{
	case 1:Insert_Sort(arr);
		break;
	case 2:Binary_Sort(arr);
		break;
	case 3:  Shell_Sort(arr);
		break;
	case 4:Bubble_Sort(arr);
		break;
	case 5:Quick_Sort(arr, 0, MAX - 1);
		break;
	case 6:Select_Sort(arr);
		break;
	case 7:Heap_Sort(arr);
		break;
	case 8:Merge_Sort(arr, 1, 20);
		break;
	default:
		break;
	}
}
void FindSort()
{
	elem arr[MAX];
	InitArr(arr);
	PrintfArr(arr);
	menu(arr);
	PrintfArr(arr);
	//PrintfArr(arr);

	/*int kk = Binary_Search(arr, 20);
	if (kk!=-1)
	{
	printf("找到了\n");
	}*/
}
void GraphQ()
{
	/*Graph g;
	InitGraph(&g);
	create(&g);
	PrinfGraph(&g);
	DFSTraval(g);
	NonerecuirsveDfs(g, 0);//图的相关操作
	printf("\n");
	BFSTraval(g);
	printf("\n");
	Djstra(g,0);
	Prim(g);*/
}
void StackandQunen()
{
	/*int i;
	SqStack S;
	InitStack(&S);
	for (i = 0; i < 10; i++)
	{
	PushStack(&S, rand() % 20);
	}
	int a = GetTop(&S);*/
	/*SQuene S;
	InitSQ(&S);
	int i;
	for (i = 0; i < 10; i++)
	{
	PushSQ(&S, rand() % 20);
	}*/
}
void TreeQ()
{
	Btree tree;
	tree.root = nullptr;
	//Point *p = tree.root;
	InitBtree(&tree);
	MidOrder(tree.root);
	printf("\n");
	PreOrder(tree.root);
	int val;
	printf("\t请输入查找元素的值：");
	while (scanf_s("%d", &val))
	{
	FindBtree(&tree, val);
	}
	/*printf("\t请输出插入元素的值：");
	while (scanf_s("%d", &val))
	{
	if (val == -1)break;
	//InsertBtree(&tree, val);
	RecursiveInsert(&tree.root, val);   //插入新节点
	MidOrder(tree.root);
	//FindBtree(&tree, val);
	}*/

	//PreOrder(tree.root);

	//PostOrder(tree.root);   //二叉树操作
}
/*
a,b,1
a, e, 1
e, b, 1
b, f, 1
c, f, 1
c, g, 1

a,b
a,e
e,b
b,f
c,f
c,g

 0  5 12 -1 -1 -1 -1 
 5  0 -1 12  2  8 -1
12 -1  0 24 -1 -1 20
-1 12  24  0 -1 -1 18
-1  2 -1 -1  0  4 15
-1  8 -1 -1	 4  0  3
-1 -1 20 18	 15  3  0
*/

void ListQ()
{
	List L;
	L.head = nullptr;
	for (int i = 0; i < 20; i++)
	{
	InitList(&L, rand() % 20);
	}
	Print(&L);
	int ch;
	while (scanf_s("%d", &ch))
	{
	Delet1(&L, ch);
	Print(&L);
	}
	//Delet(&L, 15);
	//Print(&L);
	//GetCount(&L);
	//int k;
	//scanf_s("%d", &k);
	//bool bl;
	//bl = Find(k, &L);
	//printf("%d\n", bl);   //链表操作
}