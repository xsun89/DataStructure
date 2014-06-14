#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node* createList(int num)
{
    Node* aList = (Node*)malloc(sizeof(Node));
    aList->data = 0;
    aList->next = NULL;

    Node* qT = aList;
    int i;
    for(i=0; i<num; i++)
    {
        Node *pTN = (Node*)malloc(sizeof(Node));
        pTN->data = rand()%100;
        pTN->next = NULL;
        qT->next = pTN;
        qT = pTN;
    }

    return aList;
}

void printList(Node* aList)
{
    if(aList == NULL || aList->next == NULL)
        return;

    printf("element of the list:\n\t");
    Node *pT = aList->next;

    while(pT != NULL)
    {
        printf("%d ", pT->data);
        pT = pT->next;
    }

    printf("\n");
}

Node* r_findKNode(Node* aList, int k)
{
    int i;
    Node* pT = aList;
    Node* pN = aList;
    for(i=0; i<k; i++)
    {
        pT = pT->next;
    }

    while(pT != NULL)
    {
        pT = pT->next;
        pN = pN->next;
    }

    return pN;
}

void deletList(Node* aList)
{
    if(aList == NULL)
        return;
    Node *pT = aList->next;
    while(pT != NULL)
    {
        Node* temp = pT;
        free(pT);
        pT = temp->next;
    }
    free(aList);
}

int main()
{
    srand((int)time(0));
    Node *aList = createList(7);
    printList(aList);
    Node *rk = r_findKNode(aList, 3);
    printf("%d=", rk->data);
    deletList(aList);
    return 0;
}
