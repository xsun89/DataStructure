#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

#define MAXSIZE 10000
typedef struct
{
	int r[MAXSIZE + 1];
	int length;
}SqList;

void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void print(SqList L)
{
	int i;
	for (i = 1; i < L.length;i++)
	{
		printf("%d,", L.r[i]);
	}
	printf("%d", L.r[i]);
	printf("\n");
}

void BuubleSort0(SqList *L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->r[i] > L->r[j])
			{
				swap(L, i, j);
			}
		}
	}
}

void BuubleSort1(SqList *L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		for (j = L->length-1; j >= i; j--)
		{
			if (L->r[j] > L->r[j + 1])
			{
				swap(L, j, j + 1);
			}
		}
	}
}

void BuubleSort2(SqList *L)
{
	int i, j;
	Status flag = TRUE;
	for (i = 1; i < L->length && flag; i++)
	{
		for (j = L->length - 1; j >= i; j--)
		{
			flag = FALSE;
			if (L->r[j] > L->r[j + 1])
			{
				swap(L, j, j + 1);
				flag = TRUE;
			}
		}
	}
}

void SelectSort(SqList *L)
{
	int i, j, min;
	for (i = 1; i < L->length; i++)
	{
		for (j = i + 1; j <= L->length; j++)
		{
			min = i;
			if (L->r[min] > L->r[j])
				min = j;
		}
		if (min != i)
			swap(L, min, i);
	}
}

void InsertSort(SqList *L)
{
	int out, in;
	for (out = 2; out <= L->length; out++)
	{
		in = out-1;
		int temp = L->r[out];
		while (in>0 && temp < L->r[in])
		{
			L->r[in+1] = L->r[in];
			in--;
		}
		L->r[in+1] = temp;
	}
}

void ShellSort(SqList *L)
{
	int i, j, k = 0;
	int increment = L->length;
	do 
	{
	} while (increment);
}
#define N 9
int main()
{
	int i;

	/* int d[N]={9,1,5,8,3,7,4,6,2}; */
	int d[N] = { 50, 10, 90, 30, 70, 40, 80, 60, 20 };
	/* int d[N]={9,8,7,6,5,4,3,2,1}; */

	SqList l0, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10;

	for (i = 0; i < N; i++)
		l0.r[i + 1] = d[i];
	l0.length = N;
	l1 = l2 = l3 = l4 = l5 = l6 = l7 = l8 = l9 = l10 = l0;
	printf("Before InsertSort:\n");
	print(l4);
	printf("InsertSort:\n");
	InsertSort(&l4);
	print(l4);

	system("pause");
	return 0;
}