#include <iostream>
using namespace std;
int main()
{
    int p, q, n;
    scanf("%d %d %d", &p, &q, &n);
    int arr[p][q] = {{0}};

    for (int i = 0; i < n; i++)
    {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        arr[x][y] = v;
    }

    int r, c;
    scanf("%d %d", &r, &c);
    int cnt = 0;
    if (arr[r][c] != 0)
    {
        cnt++;
        printf("%d %d %d", r, c, arr[r][c]);
        printf("1 ");
    }

    if (arr[r + 1][c] != 0)
    {
        cnt++;
        printf("%d %d %d", (r + 1), c, arr[r + 1][c]);
        printf("1 ");
    }

    if (arr[r + 1][c + 1] != 0)
    {
        cnt++;
        printf("%d %d %d", r + 1, c + 1, arr[r + 1][c + 1]);
        printf("2 ");
    }

    if (arr[r][c + 1] != 0)
    {
        cnt++;
        printf("%d %d %d", r, c + 1, arr[r][c + 1]);
        printf("3 ");
    }
    // printf("%d", cnt);
    // cout << " ";

    r = r - 1;
    c = c + 1;
    //  cout << r << c << " ";

    while (cnt != n)
    {

        while (r >= 0)
        {
            if (arr[r][c] != 0)
            {
                cout << r << c << arr[r][c] << "3 ";
                cnt++;
            }
            r -= 1;
            cout << r << c << " ";
        }
        if (r < 0)
            r = 0;
        c -= 1;
        cout << r << c;
        //     while (c >= 0)
        //     {
        //         if (arr[r][c] != 0)
        //         {
        //             cout << r << c << arr[r][c] << "4 ";
        //             cnt++;
        //         }
        //         c--;
        //     }
        //     // c = 0;
        //     // if (r == 0 && c == 0 && arr[r][c] != 0)
        //     // {
        //     //     cout << r << c << arr[r][c] << "4 ";
        //     //     cnt++;
        //     // }

        //     r = r + 1;
        //     c = 0;
        //     while (r < p)
        //     {
        //         if (arr[r][c] != 0)
        //         {
        //             cnt++;
        //             cout << r << c << arr[r][c] << "1 ";
        //         }
        //         r++;
        //     }
        //     r -= 1;
        //     c += 1;
        //     while (c < q)
        //     {

        //         if (arr[r][c] != 0)
        //         {
        //             cnt++;
        //             cout << r << c << arr[r][c] << "2 ";
        //         }
        //         c++;
        //     }
        //     c -= 1;
        //     r -= 1;
        // }
    }
    return 0;
}
