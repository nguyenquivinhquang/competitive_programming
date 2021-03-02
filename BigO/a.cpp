#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int winner[4], n, m;
int candidate[101][4];
ll findWinner(int city) {
    int x = city;
    if (candidate[x][1] > candidate[x][2] && candidate[x][1] > candidate[x][3] )
        return 1;
    if (candidate[x][2] > candidate[x][1] && candidate[x][2] > candidate[x][3] )
        return 2;
    if (candidate[x][3] > candidate[x][2] && candidate[x][3] > candidate[x][1] )
        return 3;
    return 0;
}
ll findRes() {
    if (winner[1] > winner[2] && winner[1] > winner[3] )
        return 1;
    if (winner[2] > winner[1] && winner[2] > winner[3] )
        return 2;
    if (winner[3] > winner[2] && winner[3] > winner[1] )
        return 3;
    return 0;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    memset(candidate, 0, sizeof(candidate));
    cin >> n >>m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        candidate[x][y]+=1;
    }
    for (int i = 1; i <= n; i++) {
        winner[findWinner(i)]++;
        
    }
    // cout << findWinner(1) << endl;
    // cout << winner[3];
    cout << findRes();
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/