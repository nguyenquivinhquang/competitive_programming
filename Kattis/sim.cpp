// kattis sim
#include <bits/stdc++.h>
const int N = 100009;

using namespace std;

void solve() {
    
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int testcase;
    cin >> testcase;cin.ignore();
    while (testcase--) {
        list<char> a;
        string str;
        getline(cin, str);
        auto it = a.begin();
        for (auto c : str) {
            if (c == '<') {
                if (it == a.begin()) continue;
                it--;
                it = a.erase(it);
            }  else if ( c== '[') it = a.begin();
            else if (c == ']') it = a.end();
            else a.insert(it, c);
        }
        for (auto c : a)
            cout << c;
        cout << "\n";
    }
}
