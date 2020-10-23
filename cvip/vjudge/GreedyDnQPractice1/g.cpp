#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;

int main()
{
    input_file;
    int a[10][10];
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
            printf("regionScore[%d][%d] = %d;", i, j, a[i][j]);
    }
}