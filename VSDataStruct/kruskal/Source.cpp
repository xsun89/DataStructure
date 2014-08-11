#include "Header.h"

int main()
{
	MGraph G;
	CreateMGraph(&G);
	MiniSpanTree_Kruskal(G);
	system("pause");
	return 0;
}