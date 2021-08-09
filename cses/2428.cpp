#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int n, k, temp;
ll res = 0;
queue<int> q;
map<int, int> c;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        c[temp]++;
        q.push(temp);
        while (c.size() > k) {
            int top = q.front();
            q.pop();
            c[top]--;
            if (c[top] == 0) c.erase(top);
        }
        res += q.size();
    }
    cout << res;
}

