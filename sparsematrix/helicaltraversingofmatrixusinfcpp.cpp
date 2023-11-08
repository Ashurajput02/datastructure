#include <iostream>
using namespace std;
int main()
{
    int p, q, n;
    cin >> p >> q >> n;
    // int arr[p][q] = {{0}};
    int arr[p][q];
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        arr[x][y] = v;
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int r, c;
    scanf("%d%d", &r, &c);
    int cnt = 0;
    if (arr[r][c] != 0)
    {
        cnt++;
        printf("%d%d%d", r, c, arr[r][c]);
        printf("1 ");
    }

    if (arr[r + 1][c] != 0)
    {
        cnt++;
        printf("%d%d%d", (r + 1), c, arr[r + 1][c]);
        printf("1 ");
    }

    if (arr[r + 1][c + 1] != 0)
    {
        cnt++;
        printf("%d%d%d", r + 1, c + 1, arr[r + 1][c + 1]);
        printf("2 ");
    }

    if (arr[r][c + 1] != 0)
    {
        cnt++;
        printf("%d%d%d", r, c + 1, arr[r][c + 1]);
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
        }
        if (cnt == n)
            break;
        if (r < 0)
            r = 0;
        c -= 1;

        while (c >= 0)
        {
            if (arr[r][c] != 0)
            {
                cout << r << c << arr[r][c] << "4 ";
                cnt++;
            }
            c--;
        }

        if (cnt == n)
            break;
        // c = 0;
        // if (r == 0 && c == 0 && arr[r][c] != 0)
        // {
        //     cout << r << c << arr[r][c] << "4 ";
        //     cnt++;
        // }

        r = r + 1;
        c = 0;
        while (r < p)
        {
            if (arr[r][c] != 0)
            {
                cnt++;
                cout << r << c << arr[r][c] << "1 ";
            }
            r++;
        }

        if (cnt == n)
            break;
        r -= 1;
        c += 1;
        while (c < q)
        {

            if (arr[r][c] != 0)
            {
                cnt++;
                cout << r << c << arr[r][c] << "2 ";
            }
            c++;
        }

        if (cnt == n)
            break;
        c -= 1;
        r -= 1;
    }
}
