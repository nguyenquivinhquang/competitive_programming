#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
map<string, int> check;
bool is_number(const std::string &s)
{
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}
int main()
{
    check["ABSINTH"] = 1, check["TEQUILA"] = 1, check["VODKA"] = 1;
    check["WHISKEY"] = 1, check["WINE"] = 1, check["BEER"] = 1, check["BRANDY"] = 1;
    check["CHAMPAGNE"] = 1, check["GIN"] = 1, check["RUM"] = 1, check["SAKE"] = 1;
    int n, t;
    cin >> n;
    string x;
    int res = 0;
    while (n--)
    {
        cin >> x;
        if (is_number(x))
        {
            t = stoi(x);
            if (t < 18)
                res++;
        }
        else if (check[x] == 1)
            res++;
    }
    cout << res;
}