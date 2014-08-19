#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 30
#define MAXVEX 30
#define INFINITY 65535
typedef int Status;
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;
typedef struct EdgeNode 
{
	int adjvex;
	int weight;
	struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode 
{
	int in;
	int data; 
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges; 
}GraphAdjListEntity, *GraphAdjList;

int *etv, *ltv;
int *stack2; 
int top2;

void CreateMGraph(MGraph *G)
{
	int i, j;
	G->numEdges = 13;
	G->numVertexes = 10;
	for (i = 0; i < G->numVertexes; i++)
	{
		G->vexs[i] = i;
	}
	for (i = 0; i < G->numVertexes;i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = INFINITY;
		}
	}
	G->arc[0][1] = 3;
	G->arc[0][2] = 4;
	G->arc[1][3] = 5;
	G->arc[1][4] = 6;
	G->arc[2][3] = 8;
	G->arc[2][5] = 7;
	G->arc[3][4] = 3;
	G->arc[4][6] = 9;
	G->arc[4][7] = 4;
	G->arc[5][7] = 6;
	G->arc[6][9] = 2;
	G->arc[7][8] = 5;
	G->arc[8][9] = 3;

}

void CreateALGraph(MGraph G, GraphAdjList GL)
{
	int i, j;
	EdgeNode *e;
	GL->numEdges = G.numEdges;
	GL->numVertexes = G.numVertexes;
	for (i = 0; i < G.numVertexes; i++)
	{
		GL->adjList[i].in = 0;
		GL->adjList[i].data = G.vexs[i];
		GL->adjList[i].firstedge = NULL;
	}
	for (i = 0; i < G.numVertexes; i++)
	{
		for (j = 0; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] != 0 && G.arc[i][j] < INFINITY)
			{
				e = (EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex = j;
				e->weight = G.arc[i][j];
				e->next = GL->adjList[i].firstedge;
				GL->adjList[i].firstedge = e;
				GL->adjList[j].in++;
			}
		}
	}
}

Status ToplogicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;
	int count = 0;
	int *stack;
	stack = (int *)malloc(GL->numVertexes * sizeof(int));
	for (i = 0; i < GL->numVertexes; i++)
	{
		if (0 == GL->adjList[i].in)
			stack[++top] = i;
	}

	top2 = 0;
	etv = (int *)malloc(GL->numVertexes * sizeof(int));
	for (i = 0; i < GL->numVertexes; i++)
	{
		etv[i] = 0;
	}
	stack2 = (int *)malloc(GL->numVertexes*sizeof(int));

	while (top != 0)
	{
		gettop = stack[top--];
		printf("%d -> ", GL->adjList[gettop].data);
		count++;

		stack2[++top2] = gettop;
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (!(--GL->adjList[k].in))
				stack[++top] = k;

			if ((etv[gettop] + e->weight) > etv[k])
				etv[k] = etv[gettop] + e->weight;
		}
	}
	printf("\n");
	if (count < GL->numVertexes)
		return ERROR;
	else
		return OK;

}
void CriticalPath(GraphAdjList GL)
{
	EdgeNode *e;
	int i;
	int gettop, k, j;
	int ete, lte;
	ToplogicalSort(GL);
	ltv = (int *)malloc(GL->numVertexes*sizeof(int));
	for (i = 0; i < GL->numVertexes; i++)
	{
		ltv[i] = etv[GL->numVertexes - 1];
	}
	printf("etv:\t");
	for (i = 0; i < GL->numVertexes; i++)
	{
		printf("%d-> ", etv[i]);
	}
	printf("\n");

	while (top2 != 0)
	{
		gettop = stack2[top2--];
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (ltv[k] - e->weight < ltv[gettop])
				ltv[gettop] = ltv[k] - e->weight;
		}
	}

	printf("ltv:\t");
	for (i = 0; i < GL->numVertexes; i++)
		printf("%d -> ", ltv[i]);
	printf("\n");

	for (j = 0; j < GL->numVertexes;j++)
	{
		for (e = GL->adjList[j].firstedge; e; e= e->next)
		{
			k = e->adjvex;
			ete = etv[j];
			lte = ltv[k] - e->weight;
			if (ete == lte)
				if (ete == lte)
					printf("<v%d - v%d> length: %d \n", GL->adjList[j].data, GL->adjList[k].data, e->weight);
		}
	}
}