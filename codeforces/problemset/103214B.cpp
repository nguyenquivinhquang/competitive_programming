/* 
    XXV Spain Olympiad in Informatics
    Final, day 1
    scrabble
*/


#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int n;
vector<string> dict;
map<char, int> trace;
signed main() {
    // freopen("E:\\Competitive_Programming\\codeforces\\problemset\\input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    // cout << n << endl;
    string temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        dict.push_back(temp);
    }
    char c;
    int res = 0;
    while (cin >> c) {
        trace[c]++;
    }
    for (auto str : dict) {
        map<char, int> trace2;
        for (auto c : str) trace2[c]++;
        bool check = true;
        for (auto v : trace2) {
            char c = v.first; int sl = v.second;
            if (trace[c] < sl) check = false;
        }
        if (check == true) {
            int si = str.size();
            if (si > 3) si *= 2;
            res = max(res, si);
        }
    }
    cout << res;
}
