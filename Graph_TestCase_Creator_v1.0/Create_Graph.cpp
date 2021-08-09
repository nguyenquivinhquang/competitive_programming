#include <bits/stdc++.h>
#include <dir.h>
#define Nmax (int)1E5 + 1
#define maxval (int)1E6 + 1
#define so_test (int)501
using namespace std;
long n, m;
long dinh[so_test];
long canh[so_test];
vector<long> Edges[Nmax];
stack<long> S;
int BFS(long n, long m) {
    queue<long> Q;
    long ok[Nmax];
    for (long u = 1; u <= n; u++)
        ok[u] = 0;
    Q.push(1);
    ok[1] = 1;

    while (!Q.empty()) {
        long u = Q.front();
        //cout<<u<<endl;
        Q.pop();
        for (long v = 0; v < Edges[u].size(); v++)
            if (!ok[Edges[u][v]]) {
                Q.push(Edges[u][v]);
                ok[Edges[u][v]] = 1;
            }
    }
    for (long u = 1; u <= n; u++)
        if (!ok[u])
            return 0;
    return 1;
}
int check(long x, long y) {
    for (long i = 0; i < Edges[x].size(); i++)
        if (Edges[x][i] == y)
            return 1;
    return 0;
}
//================
void create_G(long n, long m) {
    cout << "---Number Of V= ";
    cout << n << endl;
    cout << "---Number Of E= ";
    cout << m << endl;
    if (m < n - 1 || m > n * (n - 1) / 2)
        cout << "ERROR DATA. PLEASE TRY AGIAN:" << endl;
    while (true) {
        while (!S.empty())
            S.pop();
        for (long x = 1; x <= n; x++)
            S.push(x);
        for (long x = 1; x <= n; x++)
            Edges[x].clear();
        for (long i = 1; i <= m; i++) {
            long x, y;
            while (true) {
                if (!S.empty()) {
                    x = S.top();
                    S.pop();
                } else
                    x = 1 + (rand() % n);
                y = 1 + (rand() % n);
                if ((x != y) && (!check(x, y)))
                    break;
            }
            Edges[x].push_back(y);
            Edges[y].push_back(x);
        }

        if (BFS(n, m))
            break;
    }
}
vector<pair<pair<int,int>, int>>  output(int n, int m) {
    vector<pair<pair<int,int>, int>> edges;
    create_G(n, m);
    for (long x = 1; x <= n; x++)
        for (long y = 0; y < Edges[x].size(); y++)
            if (x < Edges[x][y])
                edges.push_back({{x,Edges[x][y]},1 + rand() % maxval});
                
    return edges;
}

