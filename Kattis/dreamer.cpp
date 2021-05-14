#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("//mnt//CODE/competitive_programming//cvip/vjudge// Exhaustive Search - Implementation//input.txt", "r", stdin);
#define output_file freopen("Out.txt", "w", stdout);
using namespace std;
struct days
{
    int day, month, year;
};
bool check_leap_year(int y)
{
    if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
        return true;
    return false;
}
bool check(vector<char> &str)
{
    int day = (str[0] - '0') * 10 + str[1] - '0';
    int month = (str[2] - '0') * 10 + str[3] - '0';
    int year = 0;
    for (int i = 4; i <= 7; i++)
        year = year * 10 + str[i] - '0';

    if (day > 31 || month > 12 || year < 2000 || month < 1 || day < 1 || (day > 29 && month == 2))
        return false;
    else if ((day > 30) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
        return false;
    else if (month == 2 && day > 28 && check_leap_year(year) == false)
        return false;
    else
        return true;
}
bool cmp(days a, days b)
{
    if (a.year == b.year)
    {
        if (a.month == b.month)
        {
            return a.day > b.day;
        }
        else
            return a.month > b.month;
    }
    else
        return a.year > b.year;
}
void solve()
{
    vector<ll> debug;
    days a, result;
    result = {99, 99, 9999};
    vector<char> res;
    string d, m, y;
    int total = 0;
    cin >> d >> m >> y;
    d = d + m + y;
    for (int i = 0; i < d.length(); i++)
        res.push_back(d[i]);
    sort(res.begin(), res.end());
    d = m = y = "";
    do
    {
        if (check(res) == true)
        {
            int day = (res[0] - '0') * 10 + res[1] - '0';
            int month = (res[2] - '0') * 10 + res[3] - '0';
            int year = 0;
            for (int i = 4; i <= 7; i++)
                year = year * 10 + res[i] - '0';
            a = {day, month, year};
            if (cmp(result, a))
                result = a;
            total++;
            //debug.push_back(day * 1000000 + month * 10000 + year);
        }
    } while (next_permutation(res.begin(), res.end()));

    cout << total;
    if (total != 0)
    {
        d = to_string(result.day);
        if (d.length() < 2)
            d = '0' + d;
        m = to_string(result.month);
        if (m.length() < 2)
            m = '0' + m;
        y = to_string(result.year);
        cout << " " << d << " " << m << " " << y;
    }
    cout << endl;
}
int main()
{
    //output_file;
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    // string a = "30022844";
    // vector<char> res;
    // for (int i = 0; i < a.length(); i++)
    //     res.push_back(a[i]);
    // cout << check(res);
}
