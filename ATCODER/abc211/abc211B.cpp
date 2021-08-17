#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

bool check(string str, string c) {
    if (str.find(c) == -1 ) return false;
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    map<string,int> cond;
    // cond["3B"] = 0, cond["HR"] = 0; cond["2B"] = 0; cond["H"] = 0;
    for (int i = 1; i <= 4; i++) {
        string str;
        cin >> str;
        
        cond[str]++;
    }
    if (cond.size() == 4) cout << "Yes";
    else cout << "No";
}
    
    
