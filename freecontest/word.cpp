#include <bits/stdc++.h>
#define N 1009
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
string a[N];
int n, m;
bool check(string x)
{
    for (int i = 1; i <= n; i++)
        if (x == a[i])
            return true;
    return false;
}
int main()
{
    //fastio;
    string temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    while (m--)
    {
        cin >> temp;
        if (check(temp))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}