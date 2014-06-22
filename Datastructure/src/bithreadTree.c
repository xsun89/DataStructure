#include <stdio.h>
#include <stdlib.h>

typedef enum {link, threading} BiThTag;
typedef struct BiThreadTreeNode
{
    char data;
    struct BiThreadTreeNode* lchild;
    struct BiThreadTreeNode* rchild;
    BiThTag ltag;
    BiThTag rtag;
} BiThreadTreeNode, *BiThreadTree;

void createBiThreadTree(BiThreadTree* T)
{
    char c;
    scanf("%c", &c);
    if(' ' == c){
        (*T) = NULL;
    }else
    {
        (*T) = (BiThreadTreeNode*)malloc(sizeof(BiThreadTreeNode));
        (*T)->data = c;
        createBiThreadTree(&(*T)->lchild);
        (*T)->ltag = link;
        createBiThreadTree(&(*T)->rchild);
        (*T)->rtag = link;
    }
}

void inThreadTree(BiThreadTree* H, BiThreadTree T)
{

}

int main()
{
    BiThreadTree t, h;
    createBiThreadTree(&t);
    inThreadTree(&h, t);
    return 0;
}
