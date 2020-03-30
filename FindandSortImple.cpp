#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"FindandSort.h"
;
void InitArr(elem arr[])
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		arr[i]->key = rand() % 20;
	}
}
void PrintfArr(elem arr[])
{
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]->key);
	}
	printf("\n");

}
int Search(elem arr[], int k)
{
	for (int i = 0; i < MAX; i++)
	{
		if (arr[i]->key == k)return i;
	}
	printf("没有找到！\n");
	return -1;
}

int Binary_Search(elem a[], int k)
{
	int low, high,mid;
	low = 0;
	high = MAX-1;//length
	while (low < high)
	{
		mid = (low + high) / 2;
		if (k < a[mid]->key)
		{
			high = mid - 1;
		}
		else if (k > a[mid]->key)
		{
			low = mid + 1;
		}
		else if (k == a[mid]->key)
		{
			return mid;
		}
	}
	printf("没有找到！\n");
	return -1;
}
//int next[MAX];
void get_next(char s[], int next[])
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < strlen(s))
	{
		if (j == 0 || s[i] == s[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
int KMP(char s1[], char s2[], int next[],int pos)
{
	int i,j;
	i = pos; j = 1;
	while (i <=strlen(s1) && j <= strlen(s2))
	{
		if (j == 0 || s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j > strlen(s2))
	{
		printf("匹配成功\n");
			return i-strlen(s2);
	}

	else
	{
		printf("匹配失败\n");
		return 0;
	}
}
void KMP1(char s1[], char s2[],int next[])
{
	int i, j;
	for (;;);
}
int len = MAX;
void Insert_Sort(elem arr[])
{
	int i, j;
	//int len = MAX;
	int kk;
	for (i = 1; i < len; i++)
	{
		if (arr[i]->key < arr[i-1]->key)
		{
			kk = arr[i]->key;
			for (j = i-1; kk < arr[j]->key; j--)
			{
				arr[j + 1]->key = arr[j]->key;
			}
			arr[j + 1]->key = kk;
		}
	}
}
void Binary_Sort(elem arr[])
{
	int low, high, mid,i,kk,j;
	low = 0; high = 0;
	for (i = 1; i < len; i++)
	{
		kk = arr[i]->key;
		low = 0, high = i - 1;
		while(low<=high)
		{
			mid = (low + high) / 2;
			if (arr[mid]->key < kk)low = mid + 1;
			else high = mid - 1;
		}
		for (j = i - 1; j > high; j--)arr[j + 1]->key = arr[j]->key;
		arr[high + 1]->key = kk;
	}
}
void Shell_Sort(elem arr[])
{
	int i, j, kk, dk;
	for(dk=len/2;dk>=1;dk=dk/2)
		for (i = dk; i < len; i += dk)
		{
			if (arr[i]->key < arr[i - dk]->key)
			{
				kk = arr[i]->key;
				for (j = i - dk; arr[j]->key > kk&&j>=0; j -= dk)
					arr[j + dk]->key = arr[j]->key;
				arr[j + dk]->key = kk;
			}
		}

}
void Bubble_Sort(elem arr[])
{
	int i, j,temp;
	bool flag;
	for (i = 0; i < len; i++)
	{
		flag = false;
		for(j=len-1;j>i;j--)
			if (arr[j - 1]->key > arr[j]->key)
			{
				temp = arr[j]->key;
				arr[j]->key = arr[j - 1]->key;
				arr[j - 1]->key = temp;
			}
		if (flag == false)return;
	}
}
int Partion(int low, int high, elem arr[])
{
	int pos = arr[low]->key;
	while (low < high)
	{
		while (low < high&&arr[high]->key >= pos)high--;
		arr[low]->key = arr[high]->key;
		while (low < high&&arr[low]->key <= pos)low++;
		arr[high]->key = arr[low]->key;
	}
	arr[low]->key = pos;
	return low;
}
void Quick_Sort(elem arr[],int low,int high)
{
	if (low < high)
	{
		int pvoit = Partion(low, high, arr);
		Quick_Sort(arr, low, pvoit - 1);
		Quick_Sort(arr, pvoit+1,high);
	}
}
void Select_Sort(elem a[])
{
	int i, j, min;
	for (i = 0; i < len - 1; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
		{
			if (a[j]->key < a[min]->key) min = j;
		}
		if (min != i) {
			int temp = a[i]->key;
			a[i]->key = a[min]->key;
			a[min]->key = temp;
		}
	}
}
void heapfy(elem a[], int k,int n)
{
	int i,kk,tt;
	kk = a[k]->key;
	for (i = 2 *k+1; i <= n; i=2*i+1)
	{
		if (a[i]->key < a[i + 1]->key)i++;
		if (a[i]->key > kk) {
			a[k]->key = a[i]->key;
			k=i;
		}
		else break;
	}
	a[k]->key = kk;
}
void InitMaxheap(elem arr[])
{
	int i, k;
	for (i = (len / 2)-1; i >= 0; i--)
	{
		heapfy(arr, i,len);
	}
}
void Heap_Sort(elem a[])
{
	InitMaxheap(a);
	int i, temp;
	for (i = len-1; i >=0; i--)
	{
		temp = a[0]->key;
		a[0]->key= a[i]->key;
		a[i]->key = temp;
		heapfy(a, 0,i-1);
	}
}
int *B = (int*)malloc(sizeof(int)*(len + 1));
void merge(elem arr[], int low, int mid, int high)
{
	int i, j, k;
	for (i = 0; i < len; i++)B[i] = arr[i]->key;
	for (i = low-1, j = mid, k = i; i < mid&&j < high; k++)
	{
		if (B[i] < B[j])
		{
			arr[k]->key = B[i];
			i++;
		}
		else
		{
			arr[k]->key = B[j];
			j++;
		}
	}
	while (i < mid) {
		arr[k]->key = B[i];
		k++;
		i++;
	}
	while (j < high)
	{
		arr[k]->key = B[j];
		k++;
		j++;
	}
}
void Merge_Sort(elem arr[], int low,int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		Merge_Sort(arr, low, mid);
		Merge_Sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
