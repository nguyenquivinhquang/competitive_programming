#include <bits/stdc++.h>

using namespace std;
int testcase;
int main()
{

    string x, y, r1, r2;
    cin >> testcase;
    while (testcase--)
    {
        map<string, int> result;
        for (int i = 1; i <= 16; i++)
        {
            cin >> x >> y >> r1 >> r2;
            if (r1 > r2)
            {
                result[x]++;
            }
            else
            {
                result[y]++;
            }
        }
        int res = 0;
        x = "";
        for (auto v : result)
        {
            if (v.second > res)
            {
                res = v.second;
                x = v.first;
            }
        }
        cout << x << endl;
    }
}