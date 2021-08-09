#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a[1001][1001];
    int n, m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        a[i][0] = 1000000;
    }
    for (int i = 1; i <= m; i++)
    {
        a[0][i] = 0;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            a[i][0] = min(a[i][j], a[i][0]);
            a[0][j] = max(a[i][j], a[0][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ((a[i][j]==a[i][0])&&(a[i][j]==a[0][j]))
            cout<< i<<" "<<j<<endl;
}