#include <bits/stdc++.h>

#define ll long long
#define pp pair<double, double>

const int N = 1000;

using namespace std;
vector<pp> random_pos;
double randfloat() {
    return rand() / (double(RAND_MAX) + 1);
}
void create_random_position(int l, int r, int total) {
    for (int i = 1; i <= total; i++) {
        double x = rand() % (r - l) + l + randfloat();
        double y = rand() % (r - l) + l + randfloat();
        random_pos.push_back({x, y});
    }
}
double func(int x, int y) {
    return 3.5 * x + 2 * y + pow(x, 2) - pow(x, 4) - 2 * x * y - pow(y, 2);
}
void random_search_method() {
    pair<int, pp> res = {-1e9, {-1, -1}};
    for (auto v : random_pos) {
        double f = func(v.first, v.second);
        if (res.first < f) res = {f, v};
        cout << f << endl;
    }
    cout << "x :" << res.second.first << " y: " << res.second.second << " function is: " << res.first;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    srand(time(NULL));
    int res = rand() % (50 - 3 + 1) + 3;
    create_random_position(-2, 2, 100);
    for (auto v : random_pos) {
        cout << v.first << " " << v.second << "\n";
    }
    random_search_method();
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/