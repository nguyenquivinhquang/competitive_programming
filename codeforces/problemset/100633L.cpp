#include <bits/stdc++.h>
#define int ll
#define ll long long
#define pp pair<int, int>

const int N = 300000;

using namespace std;
int n, trace[N], Max_val = 0, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp; a[i] = temp;
        trace[temp]++; 
        Max_val = max(Max_val, temp);
    }
    ll res = Max_val * trace[Max_val];
    for (int i = 1; i < n; i++) {
        // try a[i]++ , a[i+1]--
        if (a[i+1] > 0) {
            trace[a[i]]--; a[i]++; trace[a[i]]++;
            trace[a[i+1]]--;  a[i+1]--; trace[a[i+1]]++;
            if (a[i] > Max_val) res = min(res, a[i]);
            else if (trace[Max_val] > 0)  res = min(res, trace[Max_val] * Max_val);
            else {
                Max_val--;
                if (trace[Max_val]) res = min(res, trace[Max_val] * Max_val);
                Max_val++;

                Max_val++;
                if (trace[Max_val]) res = min(res, trace[Max_val] * Max_val);
                Max_val--;;
            }
            trace[a[i]]--; a[i]--; trace[a[i]]++;
            trace[a[i+1]]--;  a[i+1]++; trace[a[i+1]]++;
        }
       //try a[i]-- , a[i+1]++
        if (a[i] > 0) {
            trace[a[i]]--; a[i]--; trace[a[i]]++;
            trace[a[i+1]]--;  a[i+1]++; trace[a[i+1]]++;
            if (a[i + 1] > Max_val) res = min(res, a[i + 1] );
            else if (trace[Max_val] > 0)  res = min(res, trace[Max_val] * Max_val);
            else {
                Max_val--;
                if (trace[Max_val]) res = min(res, trace[Max_val] * Max_val);
                Max_val++;

                Max_val++;
                if (trace[Max_val]) res = min(res, trace[Max_val] * Max_val);
                Max_val--;
            }
            trace[a[i]]--; a[i]++; trace[a[i]]++;
            trace[a[i+1]]--;  a[i+1]--; trace[a[i+1]]++;
        }
    }
    cout << res;
    
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}
