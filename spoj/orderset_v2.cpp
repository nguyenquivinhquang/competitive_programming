#include <bits/stdc++.h>
#define maxn 200001
#define N 100000000
#define ll long long
#define pp pair<char, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
struct orderset
{
    int val, c;
};
orderset it[maxn * 4];
pp query[maxn];
set<int> temp;
map<int, int> compress, decompress;
int n;

void pre_processing()
{
    int c = 0;
    for (auto v : temp)
    {
        c++;
        decompress[c] = v;
        compress[v] = c;
    }
}
void update(int node, int l, int r, int pos, int val)
{
    if (pos < l || r < pos)
        return;
    if (l == r)
    {
        it[node].val = val;
        it[node].val = max(it[node].val, 0);
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, pos, val);
    update(node * 2 + 1, mid + 1, r, pos, val);
    it[node].val = it[node * 2].val + it[node * 2 + 1].val;
}
int find_k(int node, int l, int r, int k)
{
    if (it[node].val < k)
        return -1;
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (it[node * 2].val >= k)
        return find_k(node * 2, l, mid, k);
    else
        return find_k(node * 2 + 1, mid + 1, r, k - it[node * 2].val);
}
int count_k(int node, int l, int r, int k)
{
    if (k <= l)
        return 0;
    if (k > r)
        return it[node].val;
    int mid = (l + r) / 2;
    return count_k(node * 2, l, mid, k) + count_k(node * 2 + 1, mid + 1, r, k);
}
//////////////////uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu///////////////////
int main()
{
    fastio;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> query[i].first >> query[i].second;
        if (query[i].first != 'K')
            temp.insert(query[i].second);
    }
    pre_processing();
    for (int i = 1; i <= n; i++)
    {
        if (query[i].first != 'K')
        {
            query[i].second = compress[query[i].second];
            if (query[i].first == 'I')
                update(1, 1, maxn, query[i].second, 1);
            if (query[i].first == 'D')
                update(1, 1, maxn, query[i].second, -1);
            if (query[i].first == 'C')
                cout << count_k(1, 1, maxn, query[i].second) << endl;
        }
        else
        {
            int t = find_k(1, 1, maxn, query[i].second);
            if (t == -1)
                cout << "invalid";
            else
                cout << decompress[t];
            cout << endl;
        }
    }
}