#include <stdio.h>
#include <stdlib.h>
#define maxnode 4
struct node
{
    int vertexnum;
    struct node *next;
};

struct list
{
    struct list *head;
};
struct list *adjlist[maxnode] = {0};

void addnode(int s, int d)
{
    struct node *dest, *src, *temp;
    if (adjlist[s]->head == NULL)
    {
        src = (struct node *)malloc(sizeof(struct node));
        src->vertexnum = d;
        src->next = NULL;
        adjlist[s]->head = src;
    }
}
int main()
{
    int i;
    for (i = 0; i < maxnode; i++)
    {
        adjlist[i] = (struct list *)malloc(sizeof(struct list));
        adjlist[i]->head = NULL;
    }

    addnode(0, 2);
    addnode(1, 3);
    addnode(1, 2);
}