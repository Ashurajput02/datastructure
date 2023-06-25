#include <stdio.h>
int vertex = 10;
void delete(int adj[vertex + 1][vertex + 1], int delete)
{

    for (int i = 0; i < vertex + 1; i++)
        adj[i][delete] = 0;

    for (int i = 0; i < vertex + 1; i++)
        adj[delete][i] = 0;

    printf("adjacency matrix after node deleteion\n");
}
void count(int adj[vertex + 1][vertex + 1], int counter)
{
    int flag = 0;
    for (int j = 0; j < vertex + 1; j++)
    {
        if (adj[counter][j] == 1)
        {
            printf("%d\n", j);
            flag++;
        }
    }
    printf("number of iterations are:%d\n", flag);
}
void printgraph(int adj[vertex + 1][vertex + 1])
{

    for (int i = 0; i < vertex + 1; i++)
    {
        for (int j = 0; j < vertex + 1; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("enter number of  largest vertex:\n");
    int vertex12;
    scanf("%d", &vertex12);
    vertex = vertex12;
    int arr[vertex + 1][vertex + 1];

    for (int i = 0; i < vertex + 1; i++)
    {
        for (int j = 0; j < vertex + 1; j++)
        {
            arr[i][j] = 0;
        }
    }

    int s;
    int d;
    while (s != -1 && d != -1)
    {
        printf("enter source and destination vertex for a particular edge\n");
        scanf("%d%d", &s, &d);
        arr[s][d] = 1;
        arr[d][s] = 1;
    }

    printgraph(arr);
    int src;
    printf("enter for number of edges to be found?\n");
    scanf("%d", &src);
    count(arr, src);

    printf("enter node which is to be deleted\n");
    int deletenode;
    scanf("%d", &deletenode);

    delete (arr, deletenode);

    printgraph(arr);
    return 0;
}