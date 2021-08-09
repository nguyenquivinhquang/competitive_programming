#include <bits/stdc++.h>
#define int ll 
#define ll long long
#define pp pair<int, int>

const int N = 2000;

using namespace std;

int n,m, res = 0;
char house[N][N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> house[i][j];
            
        }
   

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (house[i][j] == '.') continue;
            bool check = false;
            for (int x = -1; x <= 1; x++) 
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    if (house[i+x][j+y] == '#')  res++;
                }
            
        }
    
    res /= 2;
    int add = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (house[i][j] == '#') continue;
            int c = 0;
            for (int x = -1; x <= 1; x++) 
                for (int y = -1; y <= 1; y++) {
                    if (house[i+x][j+y] == '#') c++;
                }
            add = max(add, c);
        }

    cout << res + add;
}
