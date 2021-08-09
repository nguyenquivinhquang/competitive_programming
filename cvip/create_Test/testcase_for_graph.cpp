#include </mnt/Code/Competitive_Programming/MyLib/MyLib.h>
#include <bits/stdc++.h>
#define cin infile
#define cout outfile
using namespace std;

unsigned int v[100001];
map<string, int> vertice_name;
int TEST;
map<int, string> vertice_id;
vector<string> vector_name;
ofstream outfile;
ifstream infile;
bool check_is_from_s_to_d(int s, int d, vector<pair<pair<int, int>, int>> e) {
    vector<bool> fee(200000, false);
    stack<int> dfs;
    dfs.push(s);
    
    vector<int> vertice[100009];
    for (auto edge : e) {
        auto [x, y] = edge.first;
        vertice[x].push_back(y);
    }
    
    while (dfs.size() != 0) {
        int u = dfs.top();
        dfs.pop();
        if (fee[u] == true) continue;
        else fee[u] = true;
        for (auto v : vertice[u])
            if (fee[v] == false) dfs.push(v);
    }
    return fee[s] == true && fee[d] == true;
}
void create_test(long long n, int query) {
    random_in_range random;
    int ver = n;
    generate_graph graph(100, true);

    long long maxi = 200000;
    int m = random.generate(n, min((n * (n - 1) / 2), maxi));
    auto edge = graph.output(n, m);
    while (check_is_from_s_to_d(1, n, edge) == false) {
        n = random.generate((ver / 3) * 2, ver);
        m = random.generate(n, min((n * (n - 1) / 2), maxi));
        if (ver > 10000) m = maxi;
        edge = graph.output(n, m);
    }
    // cerr << check_is_from_s_to_d(1, n, edge) << endl;
    cout << n << " " << m << "\n";
    for (auto e : edge) {
        auto [x, y] = e.first;
        int weight = abs(x - y);
        if (TEST > 23) weight = random.generate(100000, 100010);
        if (TEST > 27) weight = 100;
        cout << x << " " << y << " " << weight << "\n";
    }
    cerr << endl;
}
void generate(int testcase) {
    int n = 100000, q = 100;
    int cycle;
    if (testcase < 3)
        n = 10, q = 5;
    else if (testcase < 6)
        n = 100, q = 20;
    else if (testcase < 12)
        n = 1000, q = 100;
    else if (testcase < 18) n = 10000;

    create_test(n, q);
}
void generate_testcase() {
    int total_testcase = 30;
    for (int testcase = 27; testcase < total_testcase; testcase++) {
        string output = "data/input/input" + to_string(testcase) + ".txt";
        outfile.open(output.c_str());
        TEST = testcase;
        generate(testcase);
        outfile.close();
        cerr << testcase << "\n";
    }
}
signed main() {
    srand(time(NULL));
    generate_testcase();
}