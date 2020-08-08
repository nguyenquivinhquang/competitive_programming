#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
vector<int> a[maxn];
int n, root;
bool fee[maxn];
char res[maxn];
void find_root()
{
    int node = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].end() - a[i].begin() > node)
        {
            node = a[i].end() - a[i].begin();
            root = i;
        }
    }
}
void Gb(int node, int value)
{
    res[node] = value;
    fee[node] = true;
    if (value==87) value=64;
    for (auto i : a[node])
    {
        if (fee[i] == false)
        {

            Gb(i, value + 1);
        }
    }
}
int main()
{
    int x, y;

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    find_root();
    memset(fee, false, sizeof(fee));
    Gb(root, 70);
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
}

/*
6
1 2
2 4
4 5
6 4
3 2

out:  B A B B C C 
*/