#include <bits/stdc++.h>
#define ll long long
#define vv vector<int>
#define reset res = 0, a.clear(), trace = trace_new
using namespace std;
vv a;
int n = 1706, res;
set<ll> trace, trace_new;
ll lim;
void display(vv &b, int sl)
{
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    cout << " sl " << sl << endl;
}
ll compute(vv &b)
{
    ll temp = 0;
    for (int i = 1; i <= n; i++)
        if (b[i] == 10)
            temp = temp * 100 + b[i];
        else
            temp = temp * 10 + b[i];
    return temp;
}
void Gb()
{
    vv b, temp, count;
    vector<vv> save;
    bool check = false;
    ll save_start = 0, save_end = 0, cal, sl = 0, x = 0;
    save.push_back(a);
    count.push_back(0);
    while (sl <= 3 && x < lim)
    {
        sl = count[save_start], b = save[save_start++];
        if (sl == 3)
            return;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                vv y;
                if (i != j)
                    for (int k = 0; k <= abs(i - j); k++)
                        if (i + k <= n)
                        {
                            y.push_back(b[i + k]);
                            temp = b;
                            temp.erase(temp.begin() + i, temp.begin() + i + k + 1);
                            int pos = j;
                            if (i < j)
                                pos = j - 1 - k + 1;
                            temp.insert(temp.begin() + pos, y.begin(), y.end());
                            //display(temp,sl+1);
                            cal = compute(temp);
                            if (trace.find(cal) == trace.end())
                            {
                                save.push_back(temp);
                                trace.insert(cal);
                                count.push_back(sl + 1);
                                //display(temp, sl + 1);
                                x++;
                            }
                        }
            }
    }
}
int main()
{
    freopen("output.txt", "w", stdout);
    
    int testcase = 0, temp;
    while (cin>>n)
    {
        testcase++;
        reset;
        if (n==0) return 0;
        a.push_back(0);
        for (int i = 1; i <= n; i++)
            cin >> temp, a.push_back(temp);
        lim = 1;
        for (int i = 1; i <= n; i++)
            lim *= i;
        cout << lim << endl;
        Gb();
    }
}