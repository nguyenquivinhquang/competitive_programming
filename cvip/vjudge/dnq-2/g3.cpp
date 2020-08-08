#include <bits/stdc++.h>
#define ll long long
#define ss string
#define vv vector<int>
using namespace std;
string a;
set<string> trace;
ll lim;
int n, res;
void display(string &b, int sl)
{
    b.erase(0, 1);
    cout << b << " sl: " << sl << endl;
}
void sort_string(string &b)
{
    for (int i = 1; i < b.length(); i++)
        for (int j = i; j < b.length(); j++)
            if (b[i] > b[j])
                swap(b[i], b[j]);
}
int search(vector<pair<ss, int>> &b, ss val, int m)
{
    int l = 0, r = m - 1, mid = (m) / 2;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (b[mid].first == val)
            return b[mid].second;
        if (b[mid].first < val)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
void Gb()
{
    ss b, temp, y;
    vector<ss> save;
    vector<pair<ss, int>> backup;
    pair<ss, int> temp2;
    vv count;
    bool check = false;
    ll start = 0, sl = 0, x = 0;
    save.push_back(a);
    count.push_back(0);
    temp2 = {a, 0};
    backup.push_back(temp2);
    trace.clear();
    while (sl <= 3 && x < lim)
    {
        sl = count[start], b = save[start++];
        if (sl == 3)
            break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                y = "";
                if (i != j)
                    for (int k = 0; k <= abs(i - j); k++)
                        if (i + k <= n)
                        {
                            y = y + b[i + k];
                            temp = b;
                            temp.erase(i, k + 1);
                            int pos = j;
                            if (i < j)
                                pos = j - k + 1;
                            if (pos < temp.size())
                                temp.insert(pos, y);
                            else
                                temp = temp + y;
                            if (trace.find(temp) == trace.end())
                            {
                                save.push_back(temp);
                                trace.insert(temp);
                                count.push_back(sl + 1);
                                temp2 = {temp, sl + 1};
                                backup.push_back(temp2);
                                x++;
                                //display(temp, sl + 1);
                            }
                        }
            }
    }
    sort_string(a);
    save.clear();
    count.clear();
    trace.clear();
    sort(backup.begin(), backup.end());
    save.push_back(a);
    count.push_back(0);
    int m = x;
    sl = 0, x = 0;
    start = 0;
    int ps = search(backup, a, m);
    if (ps != -1)
    {
        res = ps;
        return;
    }
    while (sl <= 3 && x < lim)
    {
        sl = count[start], b = save[start++];
        if (sl == 3)
            break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                y = "";
                if (i != j)
                    for (int k = 0; k <= abs(i - j); k++)
                        if (i + k <= n)
                        {
                            y = y + b[i + k];
                            temp = b;
                            temp.erase(i, k + 1);
                            int pos = j;
                            if (i < j)
                                pos = j - k + 1;
                            if (pos < temp.size())
                                temp.insert(pos, y);
                            else
                                temp = temp + y;
                            int ps = search(backup, temp, m);
                            if (ps != -1)
                            {
                                res = sl + 1 + ps;
                                return;
                            }
                            if (trace.find(temp) == trace.end())
                            {
                                save.push_back(temp);
                                trace.insert(temp);
                                count.push_back(sl + 1);
                                x++;
                            }
                        }
            }
    }
}
int main()
{
    //freopen("output.txt", "w", stdout);
    int testcase = 0;
    string temp;
    while (cin >> n)
    {
        res = 0;
        testcase++;
        if (n == 0)
            return 0;
        a = "0";
        for (int i = 1; i <= n; i++)
            cin >> temp, a = a + temp;
        lim = 1;
        for (int i = 1; i <= n; i++)
            lim *= i;
        //a=a+'0';
        if (n == 1)
            cout << temp;
        else
            Gb();
        cout << "Case " << testcase << ": " << res << endl;
    }
}
/*
6
2 4 1 5 3 6
5
3 4 5 1 2
9
5 3 9 2 8 4 1 6 7 
0

2
1
4
*/