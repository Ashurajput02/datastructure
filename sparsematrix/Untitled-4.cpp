#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    vector<pair<int, int>> ash;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    int x = 0;
    while (x != -1)
    {

        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        pair<int, int> l;
        l.first = a;
        l.second = b;
        ash.push_back(l);
        cout << "press -1 to exit";
        cin >> x;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int i=0;
    while(i<ash.size()){
        int p=ash[i].first;
        int q=ash[i].second;
        int r=p;
        int c=q;

int sim=0;
// while(sim!=1){
//         if((arr[r-1][c]!=0 && r-1>=0 &&r-1<m&&c>=0 && c<n) ||(arr[r][c-1]!=0 && r>=0 &&r<m&&c-1>=0 && c-1<n) ||
//         (arr[r-1][c-1]!=0 && r-1>=0 &&r-1<m&&c-1>=0 && c-1<n)){
//             i++;
//         }
//         else
//         sim=1;
// }
while(sim!=1){
    if((arr[r][c-1]!=0 && r<m &&r>=0 && (c-1)<n && (c-1)>=0)|| (arr[r-1][c]!=0 && (r-1)<m &&(r-1)>=0 && (c)<n && (c)>=0))
    i++;
    else
    sim=1;
}


            p=ash[i].first;
         q=ash[i].second;
         r=p;
         c=q;
         cout<<r<<c<<" ";

        while(arr[r+1][c+1]!=0 && r+1<m&&r+1>=0&&c+1<n&&c+1>=0){
            cout<<r+1<<c+1<<" ";
            r=r+1;
            c=c+1;


        }
         r=p;
        c=q;
          while(arr[r+1][c]!=0 && r+1<m&&r+1>=0&&c<n&&c>=0){
            cout<<r+1<<c<<" ";
            r=r+1;
            c=c;

        }
        r=p;
        c=q;
         while(arr[r-1][c+1]!=0 && r-1<m&&r-1>=0&&c+1<n&&c+1>=0){
            cout<<r-1<<c+1<<" ";
            r=r-1;
            c=c+1;

        }

         while(arr[r][c+1]!=0 && r<m&&r>=0&&c+1<n&&c+1>=0){
            cout<<r+1<<c<<" ";
            r=r;
            c=c+1;

        }

         r=p;
        c=q;
    
        cout<<endl;
        // cnt++;
        r=p;
        c=q;
    i++;
    
    }
return 0;
}
