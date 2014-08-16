#include "Header.h"

int main()
{
	MGraph G;
	GraphAdjListEntity GL;
	int result;
	CreateMGraph(&G);
	CreateALGraph(G, &GL);
	result = TopologicalSort(&GL);
	printf("result:%d", result);
	system("pause");
	return 0;
}