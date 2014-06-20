#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//创建二叉树，约定用户遵照前序遍历的方式
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
        printf("%c 位于第%d层 \n",c,level);
}
//前序遍历二叉树
void PreOrderTraverse(BiTree T,int level)
{
    if( T )
        {
            visit(T->data,level);
            PreOrderTraverse(T->lchild,level+1);
            //中序遍历visit(T->data,level);
            PreOrderTraverse(T->rchild,level+1);
            //后序遍历visit(T->data,level);
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
