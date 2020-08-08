#include <iostream>
#define maxn 100

using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int n, a[maxn][maxn], m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
    }
}