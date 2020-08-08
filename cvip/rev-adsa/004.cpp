#include <bits/stdc++.h>
#define maxn 101

using namespace std;
set<int> mark[maxn], mark2[maxn];
int n, total1, total2, ingredient;
map<string, int> names_to_num1, names_to_num2;
map<int, string> num_to_names1, num_to_names2;
int vertice[maxn], vertice2[maxn];
int find_num(string x, bool cond)
{
    if (cond == 1)
    {
        if (names_to_num1[x] == 0)
        {
            int t = 0;
            t = ++total1;
            names_to_num1[x] = t;
            num_to_names1[t] = x;
        }
        return names_to_num1[x];
    }
    else
    {
        if (names_to_num2[x] == 0)
        {
            int t = 0;
            t = ++total2;
            names_to_num2[x] = t;
            num_to_names2[t] = x;
        }
        return names_to_num2[x];
    }
}
void output()
{

    int m = 0, check[maxn][maxn];
    memset(check, 0, sizeof(check));
    for (int i = 1; i <= 20; i++)
        for (auto v : mark[i])
            check[i][v] = true;
    for (int i = 22; i <= 100; i++)
        for (auto v : mark2[i])
            check[i][v] = true;

    vector<string> res;
    for (int i = 1; i <= 20; i++)
        for (int j = 22; j <= 50; j++)
            if (check[i][j] == 1 && check[j][i] == 1)
            {
                res.push_back("(" + num_to_names1[i] + ", " + num_to_names2[j] + ")");
            }
    sort(res.begin(), res.end());
    for (auto v : res)
    {
        cout << v << endl;
    }
    cout << endl;
}
void pre_processing(vector<int> &x, vector<int> &y)
{
    for (auto u : x)
    {
        bool check = false;
        set<int> temp;
        if (vertice[u] == 0)
            check = true;
        for (auto v : y)
        {
            if (check == true)
                mark[u].insert(v), vertice[u]++, temp.insert(v);
            else
            {
                if (mark[u].find(v) != mark[u].end())
                    temp.insert(v);
            }
        }
        mark[u] = temp;
    }
    for (auto u : y)
    {
        bool check = false;
        set<int> temp;
        if (vertice2[u] == 0)
            check = true;
        for (auto v : x)
        {
            if (check == true)
                mark2[u].insert(v), vertice2[u]++, temp.insert(v);
            else
            {
                if (mark2[u].find(v) != mark2[u].end())
                    temp.insert(v);
            }
        }
        mark2[u] = temp;
    }
}
void reset()
{
    total1 = 0, total2 = 22;
    num_to_names1.clear(), num_to_names2.clear();
    names_to_num1.clear(), names_to_num2.clear();
    memset(vertice, 0, sizeof(vertice));
    memset(vertice2, 0, sizeof(vertice2));
    for (int i = 1; i <= 100; i++)
        mark[i].clear(), mark2[i].clear();
}
int main()
{
    int testcase, m, t;
    string temp;

    cin >> testcase;
    while (testcase--)
    {
        reset();

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            vector<int> x, y;
            cin >> temp;
            cin >> m;
            for (int i = 1; i <= m; i++)
            {
                cin >> temp;
                x.push_back(find_num(temp, 1));
            }
            cin >> m;
            for (int i = 1; i <= m; i++)
            {
                cin >> temp;
                y.push_back(find_num(temp, 0));
            }
            pre_processing(x, y);
        }
        output();
    }
}