#include <bits/stdc++.h>
#define maxn 700002
using namespace std;
int tree[maxn][27], trace[27];
string a;
int q, n;
void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node][int(a[l]) - 96] = 1;
        return;
    }
    int mid = (l + r) / 2;
    //chia nhánh
    build( node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    for (int i = 1; i <= 26; i++)
        tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
}
void debug()
{
    cout << endl;
    for (int i = 1; i <= 26; i++)
        cout << tree[1][i] << " ";
}
void update(int node, int l, int r, int id, int value )
{
    if (l <= id && id <= r)
    {
        tree[node][a[id] - 96 ]--;
        tree[node][value] ++;
        if (l == r) return;
        int mid = (l + r) / 2;
        update(node * 2, l, mid, id, value );
        update(node * 2 + 1, mid + 1, r, id, value);
    }
    return;
}
int get(int node, int l, int r, int x, int y)
{
    if (y < l || r < x)
        return 0;
    if (x <= l && r <= y)
    {

        for (int i = 1; i <= 26; i++)
            if (tree[node][i] > 0)
                trace[i] = 1;
        return 0;
    }
    int mid = (l + r) / 2;
    return (get(node * 2, l, mid, x, y) + get(node * 2 + 1, mid + 1, r, x, y));
}
int main()
{
    int temp, l, r, id;
    char character;
    memset(tree, 0, sizeof(tree));

    cin >> a >> q;
    a = '1' + a;
    n = a.length() - 1 ;
    build(1, 1, n);
    while (q--)
    {
        cin >> temp;
        if (temp == 1)
        {
            cin >> id >> character;
            update(1, 1, n, id, int(character) - 96);
            a[id] = character;
        }
        else
        {
            cin >> l >> r;
            memset(trace, 0, sizeof(trace));
            get(1, 1, n, l, r);
            int res = 0;
            for (int i = 1; i <= 26; i++)
                if (trace[i] == 1) res++;
            cout << res << endl;

        }
    }

}