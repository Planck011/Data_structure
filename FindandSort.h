#pragma once
#define MAX 20
typedef int Elem;
typedef struct {
	Elem key;

}elem[MAX];

void InitArr(elem arr[]);
void PrintfArr(elem arr[]);
int Search(elem arr[], int k);
int Binary_Search(elem a[], int k);
int KMP(char s1[], char s2[], int next[], int pos);
void get_next(char s[], int next[]);
void Insert_Sort(elem arr[]);
void Binary_Sort(elem arr[]);
void Shell_Sort(elem arr[]);
void Bubble_Sort(elem arr[]);
void Quick_Sort(elem arr[], int low, int high);
void Select_Sort(elem arr[]);
void InitMaxheap(elem arr[]);
void Heap_Sort(elem arr[]);
void Merge_Sort(elem arr[],int low,int high);


