    #include <bits/stdc++.h>
    #define maxn 100001
    #define rs memset(fee, 1, sizeof(fee))
    using namespace std;

    vector<int> tree[maxn];
    int n, subtree[maxn], centroid = 1, answer[maxn];
    bool mark[maxn];
    void dfs(int u, int pre_u)
    {
        subtree[u] = 1;
        for (auto v : tree[u])
            if (v != pre_u && mark[v] == false)
            {
                dfs(v, u);
                subtree[u] += subtree[v];
            }
    }

    int find_centroid(int u, int k, int size)
    {

        for (auto v : tree[u])
            if (k != v && mark[v] == false)
            {
                if (subtree[v] > (size / 2))
                    return find_centroid(v, u, size);
            }
        return u;
    }
    void Gb(int u, int rank)
    {
        dfs(u, 0);
        int size = subtree[u];
        int centroid = find_centroid(u, 0, size);

        mark[centroid] = true;
        answer[centroid] = rank;

        for (auto v : tree[centroid])
            if (mark[v] == false)
                Gb(v, rank + 1);
    }
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        cin >> n;
        int u, v;
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        memset(subtree, 0, sizeof(subtree));
        memset(mark, 0, sizeof(mark));
        Gb(1, 65);
        for (int i = 1; i <= n; i++)
        {
            cout << char((answer[i])) << " ";
        }
    }
    /*
    16
    1 4
    2 4
    3 4
    4 5
    5 6
    6 7
    7 8
    7 9
    6 10
    10 11
    11 12
    11 13
    12 14
    13 15
    13 16

    */