
//https://codeforces.com/gym/102028/problem/F
#include <bits/stdc++.h>
#define N 1001
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
 
char a[5 * N][7 * N];
int n, m;
vector<pp> di;
pp ss;
bool fee[5 * N][7 * N];
void preprocess()
{
    di.push_back({-1, -3}), di.push_back({-1, 3}), di.push_back({1, -3});
    di.push_back({1, 3}), di.push_back({-2, 0}), di.push_back({2, 0});
}
int bfs()
{
    fee[ss.first][ss.second] = true;
    queue<pp> q;
    queue<int> step;
    q.push(ss);
    step.push(1);
    int res = 1;
    while (q.size() != 0)
    {
        pp u = q.front();
        q.pop();
        int r = step.front();
        step.pop();
        if (a[u.first][u.second] == 'T')
            return r;
        for (auto v : di)
        {
            pp edge = {v.first + u.first, v.second + u.second};
            if (a[edge.first][edge.second] == ' ')
            {
                if (fee[edge.first + v.first][edge.second + v.second] == true)
                    continue;
                fee[edge.first][edge.second] = true;
                q.push({edge.first + v.first, edge.second + v.second});
                step.push(r + 1);
            }
        }
        res++;
    }
    return -1;
}
void solve()
{
    //fastio;
    reset(fee, false);
    //output_file;
    cin >> n >> m;
    string temp;
    getchar();
    for (int i = 1; i <= 4 * n + 3; i++)
    {
        // /cin >> b[i];
        gets(a[i]);
        for (int j = 0; j < 6 * m + 3; j++)
        {
 
            if (a[i][j] == 'S')
                ss = {i, j};
        }
    }
    cout << bfs();
}
int main()
{
 
    int testcase;
    cin >> testcase;
    preprocess();
    while (testcase--)
    {
        solve();
    }
}