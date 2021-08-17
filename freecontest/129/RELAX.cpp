#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 300009;

using namespace std;

int a[N], n;
ll prefix[N];
ll get_getPrefix(int l, int r) {
    return prefix[r] ^ prefix[l] ^ a[l]; 
}
map<int,pp> trace; //first: even, second: odd
int res = 0;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];;
    int cur = 0; prefix[0] = 0;
    trace[0].second = 1;
    for (int i = 1; i <= n; i++) {

        prefix[i] = prefix[i-1] ^ a[i];
        int find = 0^prefix[i];
       
        if (i % 2 == 1) res += trace[find].first;
        else res += trace[find].second;
        
        if (i%2==1) trace[prefix[i]].first++;
        else trace[prefix[i]].second++;
    }
    
    // for (int i = 1; i <= n; i++) {
    //     cout << prefix[i] << " ";
    // }
    // cout << "\n";
    // cout << (0^prefix[5]) << "\n";
    cout << res;
}
