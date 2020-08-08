#include <bits/stdc++.h>
#define maxn 100
#define maxnames 21
using namespace std;
int total1, total2, n;
map<string, int> names_to_num1, names_to_num2;
map<int, string> num_to_names1, num_to_names2;
vector<int> vertice(maxn);
set<int> type1, type2;
int a[maxn][maxn], number_of_occurences[maxn];
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
void build_graph(vector<int> &x, vector<int> &y)
{
    for (auto u : x)
        for (auto v : y)
            a[u][v]++, a[v][u]++;
}
void process()
{
    for (auto v : type1)
    {
        int lon = 0;
        for (int i = 21; i <= 43; i++)
            lon = max(lon, a[v][i]);
        for (int i = 21; i <= 43; i++)
            if (a[v][i] < lon || number_of_occurences[i] != number_of_occurences[v])
                a[v][i] = 0;
    }
    for (auto v : type2)
    {
        int lon = 0;
        for (int i = 1; i <= 20; i++)
            lon = max(lon, a[v][i]);
        for (int i = 1; i <= 20; i++)
            if (a[v][i] < lon || number_of_occurences[i] != number_of_occurences[v] || number_of_occurences[i] != number_of_occurences[v])
                a[v][i] = 0;
    }
}
void output()
{
    vector<string> res;
    for (int i = 1; i <= 20; i++)
        for (int j = 21; j <= 43; j++)
            if ((a[i][j] == a[j][i]) && (a[i][j] != 0))
            {
                res.push_back("(" + num_to_names1[i] + ", " + num_to_names2[j] + ")");
            }
    sort(res.begin(), res.end());
    for (auto v : res)
    {
        cout << v << endl;
    }
}
void reset()
{
    total1 = 0, total2 = 22;
    num_to_names1.clear(), num_to_names2.clear();
    names_to_num1.clear(), names_to_num2.clear();
    memset(a, 0, sizeof(a)), memset(number_of_occurences, 0, sizeof(number_of_occurences));
    type2.clear(), type1.clear();
}
int main()
{
    freopen("out.txt", "w", stdout);
    int testcase, m, t;
    string temp;
    cin >> testcase;
    while (testcase--)
    {
        reset();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> temp >> m;
            vector<int> x, y;
            for (int i = 1; i <= m; i++)
            {
                cin >> temp;
                t = find_num(temp, 1);
                x.push_back(t);
                type1.insert(t);
                number_of_occurences[t]++;
            }
            cin >> m;
            for (int i = 1; i <= m; i++)
            {
                cin >> temp;
                t = find_num(temp, 0);
                y.push_back(t);
                type2.insert(t);
                number_of_occurences[t]++;
            }
            build_graph(x, y);
        }
        process();
        output();
        cout << endl;
    }
}