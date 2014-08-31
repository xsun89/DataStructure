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