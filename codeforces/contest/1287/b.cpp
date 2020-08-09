#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<string> ss;
string s[1510];
map<int, char> f1;
map<char, int> f2;

int main()
{
    f2['S'] = 0;
    f2['E'] = 1;
    f2['T'] = 2;
    f1[0] = 'S';
    f1[1] = 'E';
    f1[2] = 'T';
    int n, k;
    ll num = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        ss.insert(s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string ans;
            for (int kk = 0; kk < k; kk++)
            {
                char cc = f1[(6 - f2[s[i][kk]] - f2[s[j][kk]]) % 3];
                ans.push_back(cc);
            }
            if (ss.count(ans))
                num++;
        }
    }
    cout << num / 3 << endl;
    return 0;
}