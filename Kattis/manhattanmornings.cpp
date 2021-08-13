#include <bits/stdc++.h>
#define int ll
#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int n;
vector<pp> a, points;
pp home, work;
bool check(pp point) {
    if (point.first < min(home.first, work.first)) return false;
    if (point.first > max(home.first, work.first)) return false;
    if (point.second < min(home.second, work.second)) return false;
    if (point.second > max(home.second, work.second)) return false;
    return true;
}
bool cmp(pp u, pp v) {
    if (u.first == v.first) return u.second < v.second;
    return u.first < v.first;
}
bool cmp2(pp u, pp v) {
    return u.second <= v.second;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> home.first >> home.second >> work.first >> work.second;
    if (home.first > work.first ) swap(home, work);
    int sw = 1;
    if (home.second > work.second ) sw = -1, home.second *= sw, work.second *= sw;
    points.push_back(home); points.push_back(work);
    pp point;

    for (int i = 1; i <= n; i++) {
        cin >> point.first >> point.second;
        point.second *= sw;
        if (check(point) == false) continue;
        points.push_back(point); 
    }   
    
    sort(points.begin(), points.end(), cmp);
    for (auto v : points) {
        auto it = lower_bound(a.begin(), a.end(), v,cmp2);
        if (it == a.end()) a.push_back(v);
        else *it = v;
    }
    cout << a.size() - 2;
}