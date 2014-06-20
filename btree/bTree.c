#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//������������Լ���û�����ǰ������ķ�ʽ
void CreateBiTree(BiTree * T)
{
    char c;
    scanf("%c",&c);
    if(' '==c)
        {
            *T=NULL;
        }
        else
        {
            *T=(BiTNode*)malloc(sizeof(BiTNode));
            (*T)->data=c;
            CreateBiTree(&(*T)->lchild);
            CreateBiTree(&(*T)->rchild);
        }
}

void visit(char c,int level)
{
        printf("%c λ�ڵ�%d�� \n",c,level);
}
//ǰ�����������
void PreOrderTraverse(BiTree T,int level)
{
    if( T )
        {
            visit(T->data,level);
            PreOrderTraverse(T->lchild,level+1);
            //�������visit(T->data,level);
            PreOrderTraverse(T->rchild,level+1);
            //�������visit(T->data,level);
        }
}

int main()
{
    int level=1;
    BiTree T=NULL;
    CreateBiTree(&T);
    PreOrderTraverse(T,level);

    return 0;
}
