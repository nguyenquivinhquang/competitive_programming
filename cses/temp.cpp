#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("//media//code//c++//cse//output.txt", "r", stdin);

  int n, k;
  cin >> n >> k;
  pair<int, int> ba[n];
  for (int i = 0; i < n; i++)
  {
    cin >> ba[i].second >> ba[i].first;
  }
  sort(ba, ba + n);
  int ans = 0, sp = -1;
  for (int i = 0; i < n; i++)
  {
    if (ba[i].second >= sp)
    {
      ans++;
      sp = ba[i].first;
    }
  }
  cout << ans << endl;
}