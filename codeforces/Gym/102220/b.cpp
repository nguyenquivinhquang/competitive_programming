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
#define output_file freopen("output.txt", "w", stdout);
#define int long long
using namespace std;

int lcm(int x, int y) {
    return x / __gcd(x, y) * y;
}

void reduce(int &a, int &b) {
    int x = __gcd(a, b);
    a /= x;
    b /= x;
    return;
}

int is_larger(int a1, int b1, int a2, int b2) {
    int x = lcm(b1, b2);
    int f1 = x/b1;
    int f2 = x/b2;

    return a1 * f1 > a2 * f2;
}

signed main()
{
    fastio;
    int testcase; cin >> testcase;
    while (testcase--) {
    	int n, m; cin >> n >> m;

        vector <int> l(m+1);
        for (int bi = 1; bi <= m; bi++)
            cin >> l[bi];
        
        vector <int> adj[m+1];
        for (int i = 0; i < n; i++) {
            int ai, bi; cin >> ai >> bi;
            adj[bi].push_back(ai);
        }

        map <int, int> sum_map;
        for (int bi = 1; bi <= m; bi++) {
            sort(adj[bi].begin(), adj[bi].end(), greater<int>());

            int tmp = 0;
            for (int i = 0; i < l[bi]-1; i++) 
                tmp += adj[bi][i];
            for (int i = l[bi]-1; i < adj[bi].size(); i++) {
                tmp += adj[bi][i];
                sum_map[i+1] += tmp;
                tmp = 0;
            }
        }        

        int num = 0, den = 1;
        int cumu = 0;
        for (int C = 1; C <= n; C++) {
            cumu += sum_map[C];
            //cout << "Cumu\t" << cumu << ' ' << C << '\n';
            if (is_larger(cumu, C, num, den)) {
                num = cumu;
                den = C;
                reduce(num, den);
            }
        }

        cout << num << '/' << den << '\n';
    }
}