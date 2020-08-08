#include <bits/stdc++.h>
#define forinc(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
int n, a[101][101], res = INT_MAX, d[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ok(int u, int v, int mi, int ma)
{
   return (u > 0 && v > 0 && u <= n && v <= n && a[u][v] >= mi && a[u][v] <= ma && !d[u][v]);
}
int check(int mi, int ma)
{
   queue<pair<int, int>> q;
   forinc(i, 1, n) forinc(j, 1, n) d[i][j] = 0;
   d[1][1] = 1;
   q.push({1, 1});
   while (!q.empty())
   {
      int x = q.front().first;
      int y = q.front().second;
      if (x == n && y == n)
         return true;
      q.pop();
      forinc(i, 0, 3)
      {
         int x1 = x + dx[i];
         int y1 = y + dy[i];
         if (ok(x1, y1, mi, ma))
         {
            d[x1][y1] = 1;
            q.push({x1, y1});
         }
      }
   }
   if (d[n][n])
      return true;
   return false;
}
main()
{
   freopen("3.inp", "r", stdin);
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin >> n;
   forinc(i, 1, n) forinc(j, 1, n) cin >> a[i][j];
   forinc(i, 0, a[1][1]) //min
   {
      int l = 0, r = 120;
      while (l <= r)
      {
         int mid = (l + r) >> 1; //do chenh
         if (check(i, i + mid))
         {
            res = min(res, mid);
            r = mid - 1;
         }
         else
            l = mid + 1;
      }
   }
   cout << res;
}
