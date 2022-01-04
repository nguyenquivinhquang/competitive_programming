#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll, ll>
#define maxn 10000009
// #define cin infile
#define cout outfile
#define int long long
using namespace std;
 
ofstream outfile;
ifstream infile;
mt19937 mt;
// random_in_range _random;
long long random_in_range(int min_num, int max_num) {
    uniform_int_distribution<long long unsigned> distribution(min_num, max_num);
    return distribution(mt);
}
 
void create(int n, int _min, int _max) {
    int x = random_in_range(1, 10), y= random_in_range(1, _max);
    cout << x * y << " " << (x + y) * 2;
}
void generate(int n, int m, int k) {
    
    cout << n << " " << m << " " << k << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << random_in_range(-100, 100) << " ";
        }
        cout << "\n";
    }
 
}
void generate_testcase() {
    int total_testcase = 10;
    for (int testcase = 1; testcase < 5; testcase++) {
        string output = "input/" + to_string(testcase) + ".txt";
        cerr << testcase << endl;
        outfile.open(output.c_str());
        int n,m,k;
        cin >> n >> m >> k;
        generate(n,m,k);
        outfile.close();
    }
}
 
 
signed main() {
    generate_testcase();
    // solve_after_random_input();
}