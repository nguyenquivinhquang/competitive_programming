#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k;
    int n, m;
    string s, ans;

    cin >> n;
    cin >> s;

    set<int> room;
    for (i = 0; i < 10; i++)
        ans.push_back('0'), room.insert(i);

    for (i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            k = *room.begin(), room.erase(k), ans[k] = '1';

        else if (s[i] == 'R')
            k = *room.rbegin(), room.erase(k), ans[k] = '1';

        else
        {
            k = s[i] - 48;
            ans[k] = '0';
            room.insert(k);
        }
    }
    cout << ans;
}