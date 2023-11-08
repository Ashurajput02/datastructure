// #include <stdio.h>

// int main()
// {
//     printf("enter number of rows and number of columns\n");
//     int m, n;
//     scanf("%d %d", &m, &n);
//     int arr[m][n];
//     printf("enter sparse matrix elements\n");
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             scanf("%d", arr[i][j]);
//         }
//     }

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             int temp = arr[i][j];
//             arr[i][j] = arr[j][i];
//             arr[j][i] = temp;
//         }
//     }

//     printf("Transpose of above matrix is:\n");
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             printf("%d", arr[i][j]);
//         }

//         printf("\n");
//     }
// }

#include <stdio.h>

int main()
{
    printf("Enter the number of rows and number of columns: \n");
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    printf("Enter sparse matrix elements:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &arr[i][j]); // Use & to read the value
        }
    }

    // Find the transpose
    int transpose[n][m]; // Transpose matrix

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            transpose[j][i] = arr[i][j];
        }
    }

    printf("Transpose of the matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
