#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
void Gbae()
{
    int n, a[maxn], temp;
    map<int, int> check;
    cin >> n;
    for (int i = 0; i < n ; i++)
        cin >> a[i];
    for (int k = 0; k <= n * 10; k++)
    {
        temp = k + a[k % n];
        cout << temp <<" ";
        if (check[temp] == 0) check[temp] = 1;
        else
        {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase --)
    {
    	Gbae();
    }
}