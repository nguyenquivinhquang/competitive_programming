#include <bits/stdc++.h>
#define maxn 501
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int main()
{
    int n, m = 1;
    int gray[maxn][maxn];
    memset(gray, 0, sizeof(gray));
    while (m * m < n)
        m++;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            gray[i][j] = 1;
    for (int i=m; i>=1;i--)
        
}