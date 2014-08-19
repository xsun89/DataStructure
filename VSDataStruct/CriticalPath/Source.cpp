#include "Header.h"

int main(void)
{
	MGraph G;
	GraphAdjListEntity GL;
	CreateMGraph(&G);
	CreateALGraph(G, &GL);
	CriticalPath(&GL);
	system("pause");
	return 0;
}