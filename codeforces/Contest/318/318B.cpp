#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
string str;
set<int> pos_ss, pos_ee;
ll res = 0;
void find_substring(string substring, set<int> &a) {
    bool check = true;
    size_t pre = 0;
    while (check) {
       size_t found=str.find(substring, pre);
//       cout << found << endl;
       if (found != std::string::npos) {
            a.insert(found);
            pre = found + 1;
       } else return;
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >> str;
    find_substring("heavy", pos_ss);
    find_substring("metal", pos_ee);
    vector<int> heavy;
    for (auto v : pos_ss)
        heavy.push_back(v);
    for (auto v : pos_ee) {
        auto it = lower_bound(heavy.begin(), heavy.end(), v) - heavy.begin();
        res += it;
    }
    cout << res;
}

