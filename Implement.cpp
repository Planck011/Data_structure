#include<stdio.h>
#include<stdlib.h>
#include"20191025\20191025\Structure.h"
#include<queue>
#include<stack>
 /*typedef struct Node {
	int data;
	Node *link;
}Node;
 typedef struct list {
	 Node *head;
	 int length;
}List;

 void InitList(List *List,int val);
 void Delet(List *L, int val);
 void Print(List *);
 void GetCount(List *L);
 bool Find(int k, List *L);
 */
void InitList(List *List, int val)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = val;
	node->link = nullptr;
	if(List->head==nullptr)
	{
		List->head=node; 
		}
	else
	{
		node->link = List->head;
		List->head = node;
	}
}
void Print(List *L) {
	Node *node=nullptr;
	for (node = L->head; node != nullptr; node = node->link)
	{
		printf("%d ->  ", node->data);
	}
	printf("\n");
}
void Delet(List *L, int val)
{
	Node* p = nullptr;
	for (p = L->head; p&&p->link; p = p->link)
	{
		if (p->link->data == val)
		{
			Node *temp = p->link;
			p->link = temp->link;
			printf("删除元素 %d 成功!\n", val);
			free(temp);
		}
	}
}
void Delet1(List *L, int i)
{
	Node* p = nullptr;
	int count = 1;
	p = L->head;
	while (p)
	{
		if (count == i-1)
		{
			while (p&&p->link != nullptr)
			{
				Node* q = p->link;
				p->link = q->link;
				free(q);
			}
		}
		count++;
		p = p->link;
		
	}
	if (count < i) {
		printf("输入错误");
		return;
	}
}
void GetCount(List *L)
{
	int cnt = 0;
	Node *p = L->head;
	for (; p; p = p->link)
	{
		cnt++;
	}
	L->length = cnt;
}
bool Find(int k,List* L)
{
	Node *p;
	int i,cnt;
	cnt = L->length;
	if (k > cnt) {
		return 0;
	}
	for (i=1,p = L->head;p ; i++,p = p->link)
	{
		if(i==cnt-k+1)
		{
			printf("查找成功，倒数第%d个数据元素的值是%d\n", k,p->data);
			return 1;
		}
	}
	return 0;
}

int RecursiveInsert(Point **root, int v)
{
	if (*root == nullptr) {

		*root = (Point*)malloc(sizeof(Point));
		(*root)->val = v;
		(*root)->lef = nullptr;
		(*root)->right = nullptr;
		//printf("%d ", (*root)->val);

		return 1;
	}
	//printf("%d ", (*root)->val);

	 if (v == (*root)->val) return 0;
	 if (v > (*root)->val)
		return RecursiveInsert(&(*root)->right, v);
	else if (v < (*root)->val)
		return RecursiveInsert(&(*root)->lef, v);
	 return 0;
}
void InsertBtree(Btree *T, int v)
{
	Point *p1 = (Point*)malloc(sizeof(Point));
	p1->val = v;
	p1->lef = nullptr;
	p1->right = nullptr;
	Point *p2;
	if (T->root == nullptr)
	{
		T->root = p1;
		return;
	}
	else {
		for (p2 = T->root; p2;)
		{
			if (v<p2->val)
			{
				if (p2->lef == nullptr)
				{
					p2->lef = p1;
					return;
				}
				else
				{
					p2 = p2->lef;
				}
			}
			else
			{
				if (p2->right == nullptr)
				{
					p2->right = p1;
					return;
				}
				else
				{
					p2 = p2->right;
				}
			}
		}
	}
}
void InitBtree(Btree *T)
{
	int a[] = { 1,2,45,24,47,23,8,3,10,44 };
	for (int i = 0; i < 10; i++)
	{
		//InsertBtree(T,a[i] );
		RecursiveInsert(&T->root, a[i]);
	}
	printf("初始化成功！\n");
}
void DeletBtree(Btree *T, int val)
{

}
void PreOrder(Point *root)
{
	if (root) {
		printf("%d ", root->val);
		PreOrder(root->lef);
		PreOrder(root->right);
	}
	
}
void MidOrder(Point *root)
{
	if (root) {
		MidOrder(root->lef);
		printf("%d ", root->val);
		MidOrder(root->right);
	}
}
void PostOrder(Point *root)
{
	if (root) {
		PostOrder(root->lef);
		PostOrder(root->right);
		printf("%d ", root->val);
	}
}

void FindBtree(Btree *T, int v)  //按值查找结点在第几层
{
	Point *p;
	p = T->root;
	int cnt = 1;
	while (p)
	{
		if (v == p->val)
		{
			printf("查找成功,该节点在第%d层\n",cnt);
			return;
		}
		else if (v > p->val)
		{
			p = p->right;
			cnt++;
		}
		else {
			cnt++;
			p = p->lef;
		}
	}
	printf("查找失败\n");
}

void InitStack(SqStack *s)
{
	s->top = -1;
}
bool StackEmpty(SqStack s)
{
	if (s.top == -1)
		return true;
	else return false;
}
void PushStack(SqStack *s, int v)
{
	if (s->top == MAXSIZE - 1)
	{
		printf("堆栈满了，进栈失败\n");
	}
	else
	{
		s->top++;
		s->val[s->top] = v;
	}
}
void PopStack(SqStack *s,int &v)
{
	if (s->top == -1)
	{
		printf("空栈！出栈失败\n");
	}
	else
	{
		v = s->val[s->top];
		s->top--;
	}
}

int  GetTop(SqStack *s)
{
	if (s->top == -1)
	{
		return 0;
	}
	else
	{
		return s->val[s->top];
	}
}

void InitSQ(SQuene *s)
{
	s->front = s->rear = 0;
}
bool SQEmpty(SQuene s)
{
	if (s.front == s.rear) return true;
	else return false;
}
void PushSQ(SQuene *s, int v)
{
	if ((s->rear + 1) % MAXSIZE == s->front)
	{
		printf("队列满了\n");
	}
	else
	{
		s->val[s->rear] = v;
		s->rear = (s->rear + 1) % MAXSIZE;
	}
}
void PopSQ(SQuene *s,int &x)
{
	if (s->front == s->rear)
	{
		printf("队列为空！\n");
	}
	else
	{
		x = s->val[s->front];
		s->front = (s->front + 1) % MAXSIZE;
	}
}
void InitGraph(Graph *g)
{
	int i, j;
	g->arcnum = 0; 
	g->vexnum = 0;
	for (i = 0; i < MAXSIZE; i++)
	{
		g->V[i] = '\0';
		for (j = 0; j < MAXSIZE; j++)
		{
			if (i == j)
				g->Edge[i][j] = 0;
			else
				g->Edge[i][j] = Infinite;
		}
	}
}
int locate(Graph *g, emun u,int &k)
{	
	for (int i = 0; i < g->vexnum; i++)
	{
		if (u == g->V[i])
		{
			k = i;
			return i;
		}
	}
	return 0;
}
void create(Graph *g)
{
	int n, e, j,k;
	printf("请输入顶点数：\n");
	scanf_s("%d", &n);
	g->vexnum = n;
	printf("请输入边数：\n");
	scanf_s("%d", &e);
	g->arcnum = e;
	printf("请输入顶点数据:\n");
	scanf_s("%s", g->V, n + 1);
	//printf("%s", g->V);
	printf("1.按矩阵输入 ，2按弧头弧尾输入（请选择）\n");
	int ch;
	scanf_s("%d", &ch);
	switch (ch)
	{
		
	case 1:GetArry(g);
		break;
	case 2:Menue(g);
		break;

	default:printf("非法输入！");
		break;
	}
	//static edge E[MAXSIZE];
}
void GetArry(Graph *g)
{
	int a;
	printf("请输入矩阵：\n");
	for(int i=0;i<g->vexnum;i++)
		for (int j = 0; j < g->vexnum; j++)
		{
			scanf_s("%d", &a);
			if (a == -1)
				g->Edge[i][j] = Infinite;
			else
				g->Edge[i][j] = a;
		}
}
void Menue(Graph *g)
{
	printf("请问是带权图还是非带权图（1.带权图 2.非带权图）\n");
	int choice;
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:GetEdge1(g);
	case 2:GetEdge2(g);
	default:
		break;
	}
}
void GetEdge2(Graph *g)
{
	int i;
	emun s1, s2;

	printf("请输入边的头尾节点：\n");
	i = 0;
	while (i < g->arcnum)
	{
		getchar();
		scanf_s("%c,%c", &s1, 1, &s2, 1);
		//printf("%c,%c", s1, s2);
		int a, b;
		a = locate(g, s1, a);
		b = locate(g, s2, b);
		g->Edge[a][b] = 1;
		i++;
	}
}
void GetEdge1(Graph *g)
{
	int i,k;
	emun s1, s2;
	
	printf("请输入边的头尾节点和权值：\n");
	i = 0;
	while (i < g->arcnum)
	{
		getchar();
		scanf_s("%c,%c,%d", &s1, 1, &s2, 1, &k);
		//printf("%c,%c", s1, s2);
		int a, b;
		a = locate(g, s1, a);
		b = locate(g, s2, b);
		g->Edge[a][b] = k;
		i++;
	}
}

void PrinfGraph(Graph *g)
{
	
	int i, j;
	printf("顶点数据为：\n");
	for (i = 0; i < g->vexnum; i++)
		printf("%d:%c\n", i, g->V[i]);
	printf("邻接矩阵为：\n");
	for (i = 0; i < g->vexnum; i++)
	{
		for (j = 0; j < g->vexnum; j++)
		{
			if (g->Edge[i][j] == Infinite)
				printf("%8s", "∞");
			else
				printf("%8d", g->Edge[i][j]);
		}
		printf("\n");
	}

}

int FirstNeighbor(Graph *g, int v)
{
	int i;
	for (i = 0; i < g->vexnum; i++)
	{
		if (g->Edge[v][i] != Infinite&&g->Edge[v][i]!=0)
			return i;
	}
	return -1;
}
int NextNeighbor(Graph *g, int v, int w)
{
	int i;
	for (i = w + 1; i < g->vexnum; i++)
	{
		if (g->Edge[v][i] != Infinite&&g->Edge[v][i] != 0)
			return i;
	}
	return -1;
}
bool visited[MAXSIZE];
void DFSTraval(Graph g)
{
	int i, v;
	for (i = 0; i < g.vexnum; i++)
		visited[i] = false;
	printf("\n深度优先遍历序列为：");
	for (i = 0; i < g.vexnum; i++)
	{
		if(!visited[i])
			DFS(g, i);
	}
}
void DFS(Graph g, int v)                                         //深度优先遍历
{
		visit(v, g);
		visited[v] = true;
		for (int w = FirstNeighbor(&g, v); w >= 0; w = NextNeighbor(&g, v, w))
		{
			if (!visited[w])
			{
				DFS(g, w);
			}
		}
}
void NonerecuirsveDfs(Graph g, int v)
{
	SqStack S;
	InitStack(&S);
	int i, w;
	for (i = 0; i < g.vexnum; i++)
	{
		visited[i] = false;
	}
	printf("\n非递归深度优先遍历序列为：");
	visit(v, g);
	visited[v] = true;
	PushStack(&S, v);
	while (!StackEmpty(S))
	{
		for (w = FirstNeighbor(&g, S.val[S.top]); w >= 0; w = NextNeighbor(&g, S.val[S.top],w))
		{
			if (!visited[w])
			{
				visit(w, g);
				visited[w] = true;
				PushStack(&S, w);
					break;
			}
		}
		if(w<0)
			PopStack(&S, v);
	}
}
SQuene Q;
void visit(int v,Graph g)
{
	//int i;
	printf("%5c", g.V[v]);
}
void BFS(Graph g, int v)                                         //广度优先遍历
{
	visit(v,g);
	visited[v] = true;
	PushSQ(&Q, v);
	while (!SQEmpty(Q))
	{
		PopSQ(&Q, v);
		for (int w = FirstNeighbor(&g, v); w >= 0; w = NextNeighbor(&g, v, w))
		{
			if (!visited[w])
			{
				visit(w, g);
				visited[w] = true;
				PushSQ(&Q, w);
			}
		}
	}
}
void BFSTraval(Graph g)
{
	for (int i = 0; i < g.vexnum; i++)
	{
		visited[i] = false;
	}
	InitSQ(&Q);
	printf("\n广度优先遍历次序为: ");
	for (int i = 0; i < g.vexnum; i++)
	{
		if (!visited[i])
			BFS(g, i);
	}
}

void Prim(Graph g)
{
	int lowcost[MAXSIZE], adjvex[MAXSIZE];
	int i, j,k;
	for (i = 0; i < g.vexnum; i++)
	{
		lowcost[i] = g.Edge[0][i];
		adjvex[i] = 0;
	}
	
	int min ;
	printf("\n使用Prim算法的最小生成树输出边为:\n");
	for (i = 1; i < g.vexnum; i++)
	{
		j = 0;
		k = 0;
		min = Infinite;
		while (j < g.vexnum)
			{
				if (lowcost[j] != 0 && lowcost[j] < min)
				{
					min = lowcost[j];
					k = j;
				}
			j++;
		}
		printf("%5d-->%d", adjvex[k], k);
		lowcost[k] = 0;
		for (int m = 0; m < g.vexnum; m++)
		{
			if (lowcost[m] != 0 && g.Edge[k][m] < lowcost[m])
			{
				lowcost[m] = g.Edge[k][m];
				adjvex[m] = k;
			}
		}
	}	
}
int parent[MAXSIZE];
edge E[MAXSIZE];
void InitE(edge *E){

}
int Find(int *parent, int x)
{
	while (parent[x] >= 0)
		x = parent[x];
	return x;
}
void Kruskal(Graph g)
{

}

void Floyd(Graph g)
{
	int A[MAXSIZE][MAXSIZE],path[MAXSIZE][MAXSIZE];
	int i, j, k;
	for(i=0;i<g.vexnum;i++)
		for (j = 0; j < g.vexnum; j++)
		{
			A[i][j] = g.Edge[i][j];
			path[i][j] = -1;
		}
	for(k=0;k<g.vexnum;k++)
		for (i = 0; i<g.vexnum; i++)
			for (j = 0; j < g.vexnum; j++)
			{
				if (A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}
			}

}

void Djstra(Graph g,int v)
{
	int i, j;
	int dist[MAXSIZE], path[MAXSIZE];
	bool vis[MAXSIZE];
	for (i = 0; i < g.vexnum; i++)
	{
		dist[i] = g.Edge[v][i];
		if (g.Edge[v][i] < Infinite)path[i] = v;
		else
			path[i] = -1;
		vis[i] = false;
	}
	printf("\n最短路径为：");
	int min,k,m;
	vis[v] = true;
	path[v] = -1;
	for (j = 0; j < g.vexnum; j++)
	{
		min = Infinite;
		m = 0;
		while (m<g.vexnum)
		{
			if (vis[m]==false&& dist[m] < min)
			{
				min = dist[m];
				k = m;
			}
			m++;
		}
		//
		printf("%5d-->%d", path[k], k);
		vis[k] = true;
		for (int i=0;i<g.vexnum;i++)
		{
			if (vis[i] == false && dist[i] > g.Edge[k][i] + dist[k])
			{
				dist[i] = g.Edge[k][i] + dist[k];
				path[i] = k;
			}
		}
	}
}
	