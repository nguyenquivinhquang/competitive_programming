#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
struct coor {
    int x, y, i;
};

bool cmpx(coor x, coor y) {
    return x.x < y.x;
}
bool cmpy(coor x, coor y) {
    return x.y < y.y;
}

bool cmpi(coor x, coor y) {
    return x.i < y.i;
}

int h, w, n;
vector<coor> a;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> h >> w >> n;
    for (int i = 1; i <= n; i++) {
        coor temp;
        cin >> temp.x >> temp.y;
        temp.i = i;
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), cmpx);
    int cur = 0, pre = 0;
    for (auto &u : a) {
        if (u.x == pre) {
            u.x = cur;
            continue;
        }
        pre = u.x;
        u.x = ++cur;
    }
    sort(a.begin(), a.end(), cmpy);
    cur = 0, pre = 0;
    for (auto &u : a) {
        if (u.y == pre) {
            u.y = cur;
            continue;
        }
        pre = u.y;
        u.y = ++cur;
    }
    sort(a.begin(), a.end(), cmpi);
    for (auto u : a) {
        cout << u.x << " " << u.y << "\n";
    }
}
