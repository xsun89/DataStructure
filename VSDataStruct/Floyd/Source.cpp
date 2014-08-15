#include "Header.h"
int main()
{
	int v, w, k;
	MGraph G;

	Patharc P;
	ShortPathTable D; 

	CreateMGraph(&G);

	ShortestPath_Floyd(G, &D, &P);
	
	printf("各顶点间最短路径如下:\n");
	for (v = 0; v < G.numVertexes; ++v)
	{
		for (w = v + 1; w < G.numVertexes; w++)
		{
			printf("v%d-v%d weight: %d ", v, w, D[v][w]);
			k = P[v][w];				
			printf(" path: %d", v);	
			while (k != w)				
			{
				printf(" -> %d", k);	
				k = P[k][w];			
			}
			printf(" -> %d\n", w);
		}
		printf("\n");
	}
	
	printf("最短路径D\n");
	for (v = 0; v < G.numVertexes; ++v)
	{
		for (w = 0; w < G.numVertexes; ++w)
		{
			printf("%d\t", D[v][w]);
		}
		printf("\n");
	}
	
	printf("最短路径P\n");
	for (v = 0; v < G.numVertexes; ++v)
	{
		for (w = 0; w < G.numVertexes; ++w)
		{
			printf("%d ", P[v][w]);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}