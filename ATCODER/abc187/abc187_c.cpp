#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
    unordered_map<string,int> a;
    string str;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str; 
        a[str] += 1;
    }
    auto b = a;
    for (auto v : a) {
        if (v.first[0] != '!') continue;
        string str = v.first;
        str.erase(0, 1);
            if (b[str] != 0) {
            cout << str;
            return 0;
        }
    }
    cout << "satisfiable";
}
