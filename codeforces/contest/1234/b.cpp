#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const ll N = 1e6 + 10, MOD = 1e9 + 7;

deque<int>dq;
ull x, n, m, t, arr[N] = {}, ans = 0, sum = 0, mn = 2e9;
map<int, int>mp;
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
    {
        if(!mp[arr[i]] && dq.size() < m)
        {
            dq.push_front(arr[i]);
            mp[arr[i]] = 1;
        }
        if(!mp[arr[i]] && dq.size() == m)
        {
            mp[dq.back()] = 0;
            mp[arr[i]] = 1;
            dq.pop_back();
            dq.push_front(arr[i]);
        }

    }
    cout << dq.size() << endl;
    for(int i : dq)
        cout << i << " ";

    return 0;
}