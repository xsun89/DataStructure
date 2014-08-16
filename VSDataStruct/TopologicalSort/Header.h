#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXEDGE 20
#define MAXVEX 14
#define INFINITY 65535

typedef int Status;
typedef struct 
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdages;

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

void CreateMGraph(MGraph *G)
{
	int i, j;
	G->numEdages = MAXEDGE;
	G->numVertexes= MAXVEX;

	for (i = 0; i < G->numVertexes; i++)
		G->vexs[i] = i;

	for (i = 0; i<G->numVertexes;i++)
	{
		for (j = 0; j < G->numVertexes;j++)
		{
			G->arc[i][j] = 0;
		}
	}
	G->arc[0][4] = 1;
	G->arc[0][5] = 1;
	G->arc[0][11] = 1;
	G->arc[1][2] = 1;
	G->arc[1][4] = 1;
	G->arc[1][8] = 1;
	G->arc[2][5] = 1;
	G->arc[2][6] = 1;
	G->arc[2][9] = 1;
	G->arc[3][2] = 1;
	G->arc[3][13] = 1;
	G->arc[4][7] = 1;
	G->arc[5][8] = 1;
	G->arc[5][12] = 1;
	G->arc[6][5] = 1;
	G->arc[8][7] = 1;
	G->arc[9][10] = 1;
	G->arc[9][11] = 1;
	G->arc[10][13] = 1;
	G->arc[12][9] = 1;

};

void CreateALGraph(MGraph G, GraphAdjList GL)
{
	int i, j;
	EdgeNode *edgNode;
	GL = (GraphAdjList)malloc(sizeof(GraphAdjListEntity));
	GL->numVertexes = G.numVertexes;
	GL->numEdges = G.numEdages;
	for (i = 0; i < G.numVertexes;i++)
	{
		GL->adjList[i].in = 0;
		GL->adjList[i].firstedge = NULL;
		GL->adjList[i].data = G.vexs[i];
	}

	for (i = 0; i < G.numVertexes;i++)
	{
		for (j = 0; j < G.numVertexes;j++)
		{
			if (G.arc[i][j] == 1)
			{
				edgNode = (EdgeNode *)malloc(sizeof(EdgeNode));
				edgNode->adjvex = GL->adjList[j].data;
				edgNode->next = GL->adjList[i].firstedge;
				GL->adjList[i].firstedge = edgNode;
				GL->adjList[i].in++;
			}
		}
	}
}

Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode * edgeNode;
	int i, k, gettop;
	int count = 0;
	int top = 0;
	int *stack;
	stack = (int *)malloc(GL->numVertexes * sizeof(int));
	for (i = 0; i < GL->numVertexes; i++)
	{
		if (GL->adjList[i].in == 0)
		{
			stack[++top] = GL->adjList[i].data;
		}
	}
	while (top != 0)
	{
		gettop = stack[top--];
		printf("%d -> ", GL->adjList[gettop].data);
		count++;
		for (edgeNode = GL->adjList[gettop].firstedge; edgeNode; edgeNode=GL->adjList[gettop].firstedge->next)
		{
			k = edgeNode->adjvex;
			int temp = GL->adjList[k].in--;
			if (temp == 0)
				stack[++top] = k;
		}
	}
	printf("\n");
	if (count < GL->numVertexes)
		return ERROR;
	else
		return OK;
}