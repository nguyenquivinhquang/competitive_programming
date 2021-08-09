#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> a, b, c;

int main()
{
    int temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp, a.push_back(temp);
        cin >> temp, b.push_back(temp);
    }
    //cout<<a[2];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res = 0, i = 0, j = 0,co=0;
    while (i < n && j < n)
    {
        if (a[i]==b[j]) i++,j++; else
        if (a[i] < b[j])
            co++, i++;
        else
            j++, co--;
        res=max(res,co);   
    }
    cout<<res;
}
