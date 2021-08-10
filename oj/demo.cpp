#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
void summ(int b[maxn], int ss)
{
    for (int i = 0; i < ss; i++)
        b[i]++;
}
int main()
{
    int a[maxn] = {0, 1, 2, 3};
    summ(a, 4);
    for (int i = 0; i < 4; i++)
        cout << a[i] << " ";
}