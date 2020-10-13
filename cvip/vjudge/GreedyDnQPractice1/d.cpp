#include <bits/stdc++.h>
#define N 100
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);

using namespace std;
int c, s;
double average, minImbalance = 1e12;
vector<int> res[20], trace[20], a;
bool fee[N];
double compute(vector<int> &temp)
{
    int sum = 0;
    for (auto v : temp)
        sum += a[v];
    return abs(sum - average);
}
int main()
{
    //fastio;
    // input_file;
    // output_file;
    int testcase = 0, temp, aa = 0;
    while (cin >> c >> s)
    {
        int n = c;
        a.clear();
        testcase++;
        average = aa = 0.0;
        a.push_back(-1);
        for (int i = 1; i <= s; i++)
        {
            cin >> temp;
            average += temp;
            a.push_back(temp);
        }
        for (int i = 0; i < 7; i++)
            if (res[i].size() != 0)
                res[i].clear();
        reset(fee, true);
        aa = average, aa /= s, average /= c;
        sort(a.begin(), a.end());
        if (s >= c)
        {
            int t = 2 * n - s;
            for (int i = 1; i <= t; i++)
            {
                res[c - 1].push_back(s);
                fee[s] = false;
                c--, s--;
            }
            int start = 1;
            for (int i = 0; i < c && s > 0 && start <= s; i++)
            {
                res[i].push_back(start);
                start++;
                res[i].push_back(s);
                s--;
            }
        }
        else
        {
            for (int i = 0; i < s; i++)
                res[i].push_back(i + 1);
        }
        minImbalance = 0.0;
        for (int i = 0; i < n; i++)
        {
            minImbalance += compute(res[i]);
        }
        cout << "Set #" << testcase << endl;
        for (int i = 0; i < n; i++)
        {
            cout << " " << i << ":";
            for (auto v : res[i])
                cout << " " << a[v];
            cout << endl;
        }
        cout << "IMBALANCE = " << fixed << setprecision(5) << minImbalance << "\n\n";
    }
}