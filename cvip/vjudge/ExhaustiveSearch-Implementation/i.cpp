#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("r", "input.txt", stdin);
#define output_file freopen("w", "output.txt", stdout);
using namespace std;
int n, m;
bool fee[N][N];

int main()
{
    int x, y, res = 0;
    cin >> n >> m;
    reset(fee, false);
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        fee[x][y] = true;
    }
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> food;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                food.push_back(j + 1);
        bool check = true;
        for (auto x : food)
            for (auto y : food)
                if (fee[x][y] == true && x != y)
                {
                    check = false;
                    break;
                }
        if (check == true)
            res += 1;
    }
    cout << res;
}