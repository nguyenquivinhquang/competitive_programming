#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200000;

using namespace std;
bool cmp(pp x, pp y) {
    if (x.first == y.first) return x.second < y.second;
    return x.first < y.first;
}
pp circles[N];
int n;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> circles[i].first >> circles[i].second;
    sort(circles + 1, circles + 1 + n);
    int res = 0;
    pp cur;
    for (int i = 1; i < n; i++) {
        if (circles[i].first + circles[i].second < cur.first+cur.second){
            res++;
            continue;
        }
    }
    cout <<  n + 1;
}
