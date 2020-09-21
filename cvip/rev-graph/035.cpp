#include <bits/stdc++.h>
#define N 300
#define ll long long
#define pp pair<int, int>
#define Quyen "cute"
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define Quyen_reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("r", "input.txt", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
map<string, int> country;
int n, m, total = 0;
bool edge[N][N];
void cond1()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (edge[i][k] == true && edge[k][j] == true)
                    edge[i][j] = true;
    }
}
int main()
{
    //output_file;
    Quyen_reset(edge, false);
    string str, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (country[x] == 0)
            country[x] = ++total;
        cin >> str >> str >> str;
        cin >> y;
        if (country[y] == 0)
            country[y] = ++total;
        edge[country[x]][country[y]] = true;
    }
    cond1();    
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> str >> str >> str >> y;
        if (edge[country[x]][country[y]] == true)
            cout << "Fact";
        else if (edge[country[y]][country[x]] == true)
            cout << "Alternative Fact";
        else
            cout << "Pants on Fire";
        cout << endl;
    }
}