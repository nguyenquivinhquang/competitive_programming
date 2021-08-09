//scale
#include <bits/stdc++.h>

#define ll long long
#define pp pair<ll, ll>
#define int long long
const int N = 1000;
using namespace std;
vector<int> res1, res2;
ll trace[1000009], total = 0;
ll preProcess() {
    ll cur = 1;
    trace[0] = 1;
    while (cur < 1e18) {
        cur *= 3;
        trace[++total] = cur;
    }
    trace[total + 1] = 1e18;
}
pp Cut(ll x) {
    int l = 0, r = total;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (trace[mid] < x && trace[mid + 1] > x || trace[mid] == x)
            return {mid, trace[mid]};
        if (trace[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return {l, trace[l]};
}
bool checkRes1(int x) {
    res1.clear();
    while (x > 0) {
        pp t = Cut(x);
        x = x - t.second;
        res1.push_back(t.first);
    }
    if (x < 0) return false;
    reverse(res1.begin(), res1.end());
    for (int i = 0; i < res1.size(); i++) {
        int x = res1[i], y = res1[i + 1];
        if (res1[i] == res1[i + 1])
            return false;
    }
    return true;
}
bool checkRes2(int x) {
    res2.clear();
    while (x > 0) {
        pp t = Cut(x);
        x = x - t.second;
        res2.push_back(t.first);
    }
    if (x < 0) return false;
    reverse(res2.begin(), res2.end());
    for (int i = 0; i < res2.size(); i++) {
        int x = res2[i], y = res2[i + 1];
        if (res2[i] == res2[i + 1])
            return false;
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(NULL), cin.tie(NULL);
    freopen("SCALE.INP","r", stdin);
    freopen("SCALE.OUT","w", stdout);
    int x, i = 0, a = 0, b = 0;
    preProcess();
    cin >> x;
    a = x;
    while (1) {
        if (checkRes1(a) == true && checkRes2(b) == true)
            break;
//        i += 1;
        if (x < 10000000) {
            a += 1;
            b += 1;
        } else {
            a += 12936128936;
            b += 12936128936;
        }
    }
    if (res2.size() == 0)
        cout << "-1\n";
    else {
//        cout << res2.size() << "\n";
        for (auto v : res2)
            cout << v << " ";
        cout << "\n";
    }
//    cout << res1.size() << "\n";
    for (auto v : res1)
        cout << v << " ";
    cout << "\n";
    return 0;
}
