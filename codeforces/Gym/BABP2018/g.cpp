#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int check(string &x, string &y) {
    int n = x.length(), c = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] != y[i]) c++;
    }
    return c;
}
deque<char> q;
map<char,int> trace;
int n, res = 1e9;
string str;
void solve1() {
    str = "";
    while (q.front() == q.back()) {
        q.pop_front();
        trace[q.back()]--;
    }
   
    for (auto c : q) str.push_back(c);
    vector<char> a; for (auto v : trace) if (v.second > 0) a.push_back(v.first);
    sort(a.begin(), a.end());
    do {
        string b;
        for (auto v : a) for (int i = 1; i <= trace[v]; i++) b.push_back(v);
        res = min(res, check(b, str));

    } while (next_permutation(a.begin(), a.end()));
}
void solve2() {
    while (q.front() == q.back()) {
        q.pop_back();
        trace[q.front()]--;
    }
    for (auto c : q) str.push_back(c);
    vector<char> a; for (auto v : trace) if (v.second > 0) a.push_back(v.first);
    sort(a.begin(), a.end());
    do {
        string b;
        for (auto v : a) for (int i = 1; i <= trace[v]; i++) b.push_back(v);
        res = min(res, check(b, str));

    } while (next_permutation(a.begin(), a.end()));
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    char temp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        trace[temp]++;
        q.push_back(temp);
    }
    solve2(); 
    cout << res;
}   
