//https://open.kattis.com/problems/classrooms
#include <bits/stdc++.h>
// #define int long long
#define pp  pair<int, int>
using namespace std;
const int N = 200001;
int n, k, total_event = 0;
pp a[N]; // first : start, second: end
multiset<int> classrooms;
bool cmp(pp x, pp y) {
    if (x.second == y.second) return x.first < y.first;
    return x.second < y.second;
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a , a + n ,  cmp);
    for (int i = 0; i < n; i++) {
        auto it = classrooms.lower_bound(-a[i].first);
        if (it  == classrooms.end()) {
            if (classrooms.size() < k) {
                classrooms.insert(-a[i].second-1);
                total_event++;
            }
            continue;
        }
        classrooms.erase(it);
        classrooms.insert(-a[i].second-1);
        total_event++;
    }
    cout << total_event;
}
signed main() {
    solve();
}