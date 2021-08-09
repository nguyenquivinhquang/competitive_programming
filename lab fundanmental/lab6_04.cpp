#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
void ex03(string n) {
    n = n + " ";
    string temp = "", res = "";
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == ' ') {
            if (temp != " " && temp.length() > 0) {
                res = res + " " + temp;
            }
            temp = "";
        } else
            temp = temp + n[i];
    }
    res.erase(0, 1);
    cout << res;
}

int main() {
    string testcase = "  this  is an   unformatted  string ";
    ex03(testcase);
}