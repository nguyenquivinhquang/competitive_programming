#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int res = 9999;
typedef pair<int, int> ii;
vector<int> su;
map<char, int> m;
struct data
{
    int val;
    int pos;
    int suit;
};

void init()
{
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 4;
    m['5'] = 5;
    m['6'] = 6;
    m['7'] = 7;
    m['8'] = 8;
    m['9'] = 9;
    m['T'] = 10;
    m['J'] = 11;
    m['Q'] = 12;
    m['K'] = 13;
    m['A'] = 14;
    //--------------------------------------------------------------------------+

    m['s'] = 0;
    m['h'] = 1;
    m['d'] = 2;
    m['c'] = 3;
    return;
}
//--------------------------------------------------------------------------
bool cmp1(const ii a, const ii b)
{
    return a.first < b.first;
}
//--------------------------------------------------------------------------
bool cmp2(const ii a, const ii b)
{
    return a.first > b.first;
}
//--------------------------------------------------------------------------
int LongestIncreasingSubsequenceLength(vector<int> &v)
{
    if (v.size() == 0)
        return 0;
    vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }
    return length;
}
//--------------------------------------------------------------------------
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<data> save(n);
    init();
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        save[i].pos = i;
        save[i].suit = m[s[1]];
        save[i].val = m[s[0]];
    }
    for (int i = 0; i < 4; i++)
        su.push_back(i);
    do
    {
        for (int i = 0; i < 16; i++)
        {
            vector<int> L;
            for (int j = 0; j < 4; j++)
            {
                vector<ii> a;
                for (int k = 0; k < n; k++)
                    if (su[j] == save[k].suit)
                        a.push_back(ii(save[k].val, save[k].pos));
                if (i & (1 << j))
                    sort(a.begin(), a.end(), cmp1);
                else
                    sort(a.begin(), a.end(), cmp2);
                for (int k = 0; k < a.size(); k++)
                    L.push_back(a[k].second);
            }
            res = min(res, n - LongestIncreasingSubsequenceLength(L));
        }
    } while (next_permutation(su.begin(), su.end()));
    cout << res;
    return 0;
}