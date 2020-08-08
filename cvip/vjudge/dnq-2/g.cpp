#include <bits/stdc++.h>
#define pp pair<int, int>
#define maxn 11
#define vpp vector<pp>
#define ll long long
using namespace std;
vpp a, kq;
int n, testcase, res = 100000000;
set<ll> trace;
queue<vpp> quangcute;
queue<int> save;
bool check_dk(vpp &b)
{
    for (int i = 2; i <= n; i++)
    {
        if (b[i] < b[i - 1])
            return false;
    }
    return true;
}
void display(vpp &b, int sl)
{
    for (int i = 1; i <= n; i++)
        cout << b[i].first << " ";
    cout << " sl " << sl << endl;
}
ll compute(vpp &b)
{
    ll temp = 0;
    for (int i = 1; i <= n; i++)
        if (b[i].second == 10)
            temp = temp * 100 + b[i].second;
        else
            temp = temp * 10 + b[i].second;
    return temp;
}

void quangdeptraicutevaidai(vpp &a, int k, int sl)
{
    quangcute.push(a);
    save.push(0);
    vpp b, t;
    bool check = false;
    ll cal;
    while (check == false)
    {
        sl = save.front(), save.pop();
        b = quangcute.front(), quangcute.pop();
        check = check_dk(b);
        if (check == true || sl == 3)
        {
            res = sl;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                vpp y;
                if (i != j)
                    for (int k = 0; k <= abs(i - j); k++)
                    {
                        if (i + k <= n)
                        {
                            y.push_back(b[i + k]);
                            t = b;
                            //display(t,sl+1);
                            t.erase(t.begin() + i, t.begin() + i + k + 1);
                            //display(t,sl+1);
                            int pos = j;
                            if (i < j)
                                pos = j - (i + k) + 1;
                            t.insert(t.begin() + pos, y.begin(), y.end());
                            //display(t,sl+1);
                            cal = compute(t);

                            if (trace.find(cal) == trace.end())
                            {
                                quangcute.push(t);
                                trace.insert(cal);
                                save.push(sl + 1);
                                //display(t, sl + 1);
                                if (check_dk(t) == true)
                                {
                                    res = sl + 1;
                                    return;
                                }
                            }
                        }
                    }
            }
        }
    }
    res = sl;
}
int main()
{

    freopen("output.txt", "w", stdout);
    int nn = 0;
    while (cin >> n)
    {
        a.clear();

        quangcute.empty();
        trace.clear();
        if (n == 0)
            return 0;
        res = 1000000;
        int t;
        pp temp;
        testcase++;
        temp = {0, 0}, a.push_back(temp);
        for (int i = 1; i <= n; i++)
        {
            cin >> t;
            temp = {t, i};
            a.push_back(temp);
        }
        //temp = {11, 11}, a.push_back(temp);

        quangdeptraicutevaidai(a, 0, 0);
        //debug(a);
        cout << "Case " << testcase << ": " << res << endl;
        queue<int> q;
        queue<vpp> x;
        save = q;
        quangcute = x;
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
t.erase(t.begin() + j, t.begin() + j + c);
t.insert(t.begin() + i, y.begin(), y.end());
*/
