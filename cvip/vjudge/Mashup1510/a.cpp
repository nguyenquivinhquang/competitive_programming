#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define endl '\n'

using namespace std;
set<int> a;
int n, temp, res = 0;
int main()
{
    fastio;
    //output_file;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.insert(temp);
    }
    while (1)
    {
        auto it = a.end();
        it--;
        if (*a.begin() == *it)
            break;
        res++;
        int x = *it - *a.begin();
        a.erase(it);
        a.insert(x);
    }
    cout << *a.begin() << endl;
}