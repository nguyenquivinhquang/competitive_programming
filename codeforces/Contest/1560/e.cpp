#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
bool check(string s, string &erase, string &t) {
    string ans = s;
    int s_s = 0;
    while (s.length() && s_s < erase.length()) {
        string temp;
        for (auto c : s) 
            if (c != erase[s_s]) temp.push_back(c);
        s = temp;
        for (auto v : s) ans.push_back(v);
        s_s++;
    }
    return ans == t;
}
void solve() {
    string str; cin >> str;
    string ans = str, res;
    map<char, int> trace;
    int first_char = 0;
    for (auto c : str) trace[c]++;
    int n = trace.size();
    
    while (str.length()) {
        string temp ="";
        char last_char = str[str.length() - 1];
        first_char += trace[last_char] / n--;
        res.push_back(last_char);
        for (auto c : str) 
            if (c != last_char) temp.push_back(c);
        swap(str, temp);

    }
    string temp;
    reverse(res.begin(), res.end()); 
    for (int i = 0; i < first_char; i++) temp.push_back(ans[i]);
    
    if (check(temp, res, ans) == false) {
        cout << "-1\n";
        return;
    }
    cout << temp << " ";  
    for (auto c : res) cout << c;
    cout << "\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t; cin >> t;
    while (t--)solve();
}
