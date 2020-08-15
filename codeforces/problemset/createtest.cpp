#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
int main()
{
    freopen("out.txt", "w", stdout);
    cout << "100 100 100 \n";
    for (int i = 1; i <= 100; i++)
        cout << rand() % 50 << " ";
    cout << endl;
    for (int i = 1; i <= 100; i++)
        cout << rand() % 50 << " ";
    cout << endl;
    for (int i = 1; i <= 100; i++)
        cout << rand() % 50 << " ";
    cout << endl;
}