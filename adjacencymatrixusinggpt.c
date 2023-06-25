#include <stdio.h>
#include <stdlib.h>

void printGraph(int **adjMatrix, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    int vertices;
    scanf("%d", &vertices);

    int **adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
    {
        adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    int source, destination;
    while (1)
    {
        printf("Enter the source and destination vertices for an edge (-1 to stop): ");
        scanf("%d %d", &source, &destination);
        if (source == -1 || destination == -1)
            break;
        if (source >= vertices || destination >= vertices)
        {
            printf("Invalid vertex! Please enter vertices within the range of 0 to %d.\n", vertices - 1);
            continue;
        }
        adjMatrix[source][destination] = 1;
        adjMatrix[destination][source] = 1;
    }

    printGraph(adjMatrix, vertices);

    // Free allocated memory
    for (int i = 0; i < vertices; i++)
    {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}
