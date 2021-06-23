#include <bits/stdc++.h>
#define ll long long
#define Nmax (int)1E2 + 1
#define maxval (int)1E2 + 1


using namespace std;
class random_in_range {
    /*
        Random in range.
        Declare random_in_range random and call random.generate(min, max) to random from min to max

    */
    public:
        unsigned seed;
        default_random_engine generator;
        random_in_range() {
            seed = std::chrono::system_clock::now().time_since_epoch().count();
            default_random_engine generator(seed);
            this -> generator = generator;
        }
        long long unsigned generate(int min_num, int max_num) {
            uniform_int_distribution<long long unsigned> distribution(min_num, max_num);
            return distribution(generator);
        }


};
class generate_graph {
    /*
        Generate graph: 
            input: number of vertices and number of edges
            output: vector<pair<pair<int, int>, int>> : <<start,end>, cost>

    */
    private:
        ll n, m;
        
        vector<vector<ll>> Edges;
        stack<ll> S;
        int BFS(ll n, ll m) {
            queue<ll> Q;
            ll ok[Nmax];
            for (ll u = 1; u <= n; u++)
                ok[u] = 0;
            Q.push(1);
            ok[1] = 1;

            while (!Q.empty()) {
                ll u = Q.front();
                //cout<<u<<endl;
                Q.pop();
                for (ll v = 0; v < Edges[u].size(); v++)
                    if (!ok[Edges[u][v]]) {
                        Q.push(Edges[u][v]);
                        ok[Edges[u][v]] = 1;
                    }
            }
            for (ll u = 1; u <= n; u++)
                if (!ok[u])
                    return 0;
            return 1;
        }
        int check(ll x, ll y) {
            for (ll i = 0; i < Edges[x].size(); i++)
                if (Edges[x][i] == y)
                    return 1;
            return 0;
        }
        //================
        void create_G(ll n, ll m) {
            cout << "---Number Of V = ";
            cout << n << endl;
            cout << "---Number Of E = ";
            cout << m << endl;
            if (m < n - 1 || m > n * (n - 1) / 2)
                cout << "ERROR DATA. PLEASE TRY AGIAN:" << endl;
            while (true) {
                while (!S.empty())
                    S.pop();
                for (ll x = 1; x <= n; x++)
                    S.push(x);
                for (ll x = 1; x <= n; x++)
                    Edges[x].clear();
                for (ll i = 1; i <= m; i++) {
                    ll x, y;
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
    public:
        generate_graph() {
            
        }
        vector<pair<pair<int, int>, int>> output(int n, int m) {
            random_in_range random;
            this -> Edges.resize(n + 10);
            vector<pair<pair<int, int>, int>> edges;
            this -> create_G(n, m);
            for (ll x = 1; x <= n; x++)
                for (ll y = 0; y < Edges[x].size(); y++)
                    if (x < Edges[x][y])
                        edges.push_back({{x, Edges[x][y]}, random.generate(1, maxval)});

            return edges;
        }
};


