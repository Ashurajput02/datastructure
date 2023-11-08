#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int row, col, value;
};

int main()
{
    int ash, jig, sim;

    printf("Enter the number of rows: ");
    scanf("%d", &ash);
    printf("Enter the number of columns: ");
    scanf("%d", &jig);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &sim);

    if (sim > ash * jig)
    {
        printf("Invalid input: Number of non-zero elements exceeds matrix size.\n");
        return 1;
    }

    struct Element *ashMatrix = (struct Element *)malloc(sim * sizeof(struct Element));

    printf("Enter non-zero elements (row, column, value):\n");
    for (int i = 0; i < sim; i++)
    {
        int row, col, value;
        scanf("%d %d %d", &row, &col, &value);

        if (row < 0 || row >= ash || col < 0 || col >= jig)
        {
            printf("Invalid input: Index out of range.\n");
            return 1;
        }

        ashMatrix[i].row = row;
        ashMatrix[i].col = col;
        ashMatrix[i].value = value;
    }

    int tashuRows = jig;
    int tashuCols = ash;
    int numTashu = sim;

    struct Element *tashuMatrix = (struct Element *)malloc(numTashu * sizeof(struct Element));

    for (int i = 0; i < sim; i++)
    {
        tashuMatrix[i].row = ashMatrix[i].col;
        tashuMatrix[i].col = ashMatrix[i].row;
        tashuMatrix[i].value = ashMatrix[i].value;
    }

    printf("Original Sparse Matrix:\n");
    for (int i = 0; i < sim; i++)
    {
        printf("%d\t%d\t%d\n", ashMatrix[i].row, ashMatrix[i].col, ashMatrix[i].value);
    }

    printf("Transpose of the Sparse Matrix:\n");
    for (int i = 0; i < numTashu; i++)
    {
        printf("%d\t%d\t%d\n", tashuMatrix[i].row, tashuMatrix[i].col, tashuMatrix[i].value);
    }

    free(ashMatrix);
    free(tashuMatrix);

    return 0;
}
