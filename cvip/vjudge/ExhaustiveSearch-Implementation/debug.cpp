#include <bits/stdc++.h>
#define N 101
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
    int c = 0;
    output_file;
    int fee[N], m = 30;
    reset(fee, false);
    cout << "30 4 \n";
    for (int i = 2; i <= 5; i++)
    {
        cout << i << endl;
        for (int j = 0; j <= m; j++)
            if (j % i == 0)
                fee[j] = true;
    }
    for (int j = 0; j <= m; j++)
        if (fee[j] == false)
            c++;
        else
            cout << j << " ";
    cout << c;
}