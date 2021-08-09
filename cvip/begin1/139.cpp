#include <iostream>

using namespace std;

int main()
{
    int a[1000][1000];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout<<a[j][i]<<" ";
        cout<<endl;
    }
}