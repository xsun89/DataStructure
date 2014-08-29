#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef struct BiTNode
{
	int data;
	int bf;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void R_Rotate(BiTree *P)
{
	BiTree L;
	L = (*P)->lchild;
	(*P)->lchild = L->rchild;
	L->rchild = (*P);
	*P = L;
}

void L_Rotate(BiTree *P)
{
	BiTree R;
	R = (*P)->rchild;
	(*P)->rchild = R->lchild;
	R->lchild = (*P);
	*P = R;
}

#define LH +1 
#define EH 0  
#define RH -1

void LeftBalance(BiTree *T)
{
	BiTree L, Lr;
	L = (*T)->lchild;
	switch (L->bf)
	{
	case LH:
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:
		Lr = L->rchild;

		break;
	}
}
