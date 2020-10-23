// Conversation Log

#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, string>

const int N = 1000;

using namespace std;
map<string, int> trace;
map<string, set<string, int>> user;
int n;
vector<pp> res;
bool cond(pp a, pp b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
void split(string &x) {
    vector<string> a;
    string temp = "";
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == ' ') {
            a.push_back(temp);
            temp = "";
        } else
            temp = temp + x[i];
    }
    for (int i = 1; i < a.size(); i++) {
        trace[a[i]]++;
        user[a[i]].insert(a[0]);
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    string temp;
    cin >> n;
    while (getline(cin, temp)) {
       split(temp);
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/