#include "Header.h"

int main()
{

	int i, j, v0;
	MGraph G;
	Patharc P;
	ShortPathTable D; /* 求某点到其余各点的最短路径 */
	v0 = 0;

	CreateMGraph(&G);

	ShortestPath_Dijkstra(G, v0, &P, &D);

	printf("最短路径倒序如下:\n");
	for (i = 1; i < G.numVertexes; ++i)
	{
		printf("v%d - v%d : ", v0, i);
		j = i;
		while (P[j] != -1)
		{
			printf("%d ", P[j]);
			j = P[j];
		}
		printf("\n");
	}
	printf("\n源点到各顶点的最短路径长度为:\n");
	for (i = 1; i < G.numVertexes; ++i)
		printf("v%d - v%d : %d \n", G.vexs[0], G.vexs[i], D[i]);

	system("pause");
	return 0;
}