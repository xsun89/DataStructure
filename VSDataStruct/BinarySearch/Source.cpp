#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int a[15];
	int key = 28;
	for (i = 0; i < 15; i++)
	{
		a[i] = i + 21;
	}

	int min, max, mid;
	min = 0;
	max = 14;
	bool found = false;
	while (min <= max)
	{
		mid = (max + min) / 2;
		if (a[mid] < key)
		{
			min = mid + 1;
		}
		else if (a[mid] > key)
		{
			max = mid - 1;
		}
		else
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		printf("found %d\n", mid);
	}
	else
		printf("not found\n");

	system("pause");
	return 0;
}