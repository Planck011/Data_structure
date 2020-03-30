#pragma once
typedef struct Node {
	int data;
	Node *link;
}Node;
typedef struct list {
	Node *head;
	int length;
}List;

void InitList(List *List, int val);
void Delet(List *L, int val);
void Print(List *);
void GetCount(List *L);
bool Find(int k, List *L);
void Delet1(List *L, int i);

typedef struct Point {
	int val;
	Point *lef, *right;
}Point;

typedef struct tree {
	Point *root;
}Btree;

void InitBtree(Btree *T);
int RecursiveInsert(Point **root, int v);
void InsertBtree(Btree *T, int v);
void DeletBtree(Btree *T, int v);
void FindBtree(Btree *T, int v);
void PreOrder(Point *root);
void MidOrder(Point *root);
void PostOrder(Point *root);

#define MAXSIZE 20
typedef struct SqStack {
	int val[MAXSIZE] ;
	int top;
}SqStack;

void InitStack(SqStack *s);
bool StackEmpty(SqStack s);
void PushStack(SqStack *s,int v);
void PopStack(SqStack *s,int &v);
int  GetTop(SqStack *s);

typedef struct {
	int val[MAXSIZE];
	int front, rear;
}SQuene;

void InitSQ(SQuene *s);
bool SQEmpty(SQuene s);
void PushSQ(SQuene *s, int v);
void PopSQ(SQuene *s,int &x);


typedef char emun;
#define Infinite 65535
typedef struct {
	emun V[MAXSIZE];
	int Edge[MAXSIZE][MAXSIZE];
	int vexnum,arcnum;	
}Graph;
typedef struct edge{
	emun	 head;
	emun tail;
	int val;
}edge;
void InitGraph(Graph *g);
void PrinfGraph(Graph *g);
void create(Graph *g);//创建图的邻接矩阵存储
void DFSTraval(Graph g);
int locate(Graph *g, emun u, int &k);
int NextNeighbor(Graph *g, int v, int w);
int FirstNeighbor(Graph *g, int v);
//bool visited[MAXSIZE];
void DFS(Graph g, int v);
void GetEdge1(Graph *g);
void GetEdge2(Graph *g);
void GetArry(Graph *g);
void BFSTraval(Graph g);
void BFS(Graph g, int v);
void Menue(Graph *g);
void visit(int v, Graph g);
void Prim(Graph g);
void Kruskal(Graph g);
void Djstra(Graph g,int v);
void NonerecuirsveDfs(Graph g, int v);




