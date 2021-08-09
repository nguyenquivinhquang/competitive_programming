#include <bits/stdc++.h>


using namespace std;
int n;
vector<int> a;

void solve() {
    vector<int> drink, drink_count;
    int temp, total = 0;
    cin >> n;
    drink.push_back(-1);
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        if (temp == drink[drink.size() - 1]) total++;
        else {
            drink_count.push_back(total);
            total = 1;
            drink.push_back(temp);
        }
    }
    drink_count.push_back(total);
    int res = 0;
    for (int i = 1; i < drink.size(); i++) {
        res = max(res, min(drink_count[i], drink_count[i - 1]));
    }
    cout << res * 2;
}
signed main() {
    solve();
}

