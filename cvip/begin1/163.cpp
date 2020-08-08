#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int a[3][100000];

void Hoai_Thuong(int b)
{
    int temp;
    for (int i = 1; i <= b; i++)
    {
        a[1][i] = a[2][i];
        a[2][i] = 0;
    }
}
int main()
{
    int b, n;
    int m[1000001], v[101];
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> m[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (j - m[i] >= 0)
            {
                a[2][j] = max(a[1][j], a[1][j - m[i]] + v[i]);
            } else a[2][j]=a[1][j];
        }
        Hoai_Thuong(b);
    }
    cout << a[1][b];
}