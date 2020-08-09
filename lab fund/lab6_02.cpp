#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define q_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
int ex2(int n, string str[])
{
    string temp;
    vector<string> a;
    for (int i = 0; i < n; i++)
        a.push_back(str[i]);
    sort(a.begin(), a.end());
    for (auto v : a)
        cout << v << " ";
}

int main(int argc, char *argv[])
{

    // int n;
    // string str[N];
    // cin >> n;
    // for (int i = 0; i < n; i++)
    //     cin >> str[i];
    int n = atoi(argv[1]);
    string str[n];
    for (int i = 0; i < n; i++)
        str[i] = argv[i + 2];
    ex2(n, str);
}