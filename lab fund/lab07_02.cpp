#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
void ex2(char *str[], int n)
{
    map<string, int> trace;
    for (int i = 0; i < n; i++)
        trace[str[i]]++;
    cout << trace.size();
}

int main(int argc, char *argv[])
{
    char *str[] = {"ab", "abcd", "ab", "abdr"};
    ex2(str, 4);

    return 0;
}