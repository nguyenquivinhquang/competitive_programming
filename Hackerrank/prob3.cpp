//Kiếm 1 dãy con lien tiếp sao cho chênh lêch các phần tử bất kì tối đa là 1.
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int longestSubarray(vector<int> arr) {
    int res = 0;
    set<long long> _set;
    map<long long, int> trace;
    for (auto v : arr) {
        cerr << v << " ";
    }
    queue<long long> q;
    for (int i = 0; i < arr.size(); i++) {
        if (q.size() > res) res = q.size();
        q.push(arr[i]);
        trace[arr[i]]++;
        _set.insert(arr[i]);
        while (_set.size() > 2 && q.size() != 0) {
            int x = q.front();
            q.pop();
            trace[x]--;
            if (trace[x] == 0) {
                auto it = _set.find(x);
                if (it != _set.end()) _set.erase(x);
            }
        }
        if (_set.size() <= 1) continue;
        if (_set.size() == 3)  cerr << i;
        auto it = _set.begin();
        it++;
        cerr << _set.size() << "\n";
        if (abs(*_set.begin() - *it) > 1) {
            _set.clear();
            while (q.size() != 0) q.pop();
            trace.clear();
            q.push(arr[i]);
            trace[arr[i]]++;
            _set.insert(arr[i]);
        }
    }
    if (q.size() > res) res = q.size();
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << longestSubarray(arr);
}
