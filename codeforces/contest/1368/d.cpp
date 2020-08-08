#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int main()
{
    int n, temp;
    multiset<int, greater<int>> a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.insert(temp);
    }
    for (auto v : a)
        cout << v << " ";
}