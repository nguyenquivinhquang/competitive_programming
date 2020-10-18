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
#define output_file freopen("input.txt", "w", stdout);
using namespace std;

int main()
{
    srand(time(NULL));
    output_file;
    for (int t = 1; t <= 3; t++)
    {
        cout << 10 << endl;
        for (int i = 1; i <= 10; i++)
        {

            double x = rand() % (100) - 30;
            double y = rand() % (100) - 30;
            cout << x << " " << y << endl;
        }
    }

    cout << 0;
}