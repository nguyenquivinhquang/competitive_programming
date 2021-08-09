#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

pp a[N];
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, c;
    string temp;
    cin >> n >> c;
    int minu = 0, hour = 0, sec = 0;
    for (int k = 1; k <= n; k++)
    {
        cin >> temp;
        int i = 0;
        while (temp[i] != ':')
        {
            a[k].first = a[k].first * 10 + (temp[i] - '0');
            i++;
        }
        i++;
        while (i < temp.length())
        {
            a[k].second = a[k].second * 10 + (temp[i] - '0');
            i++;
        }
        sec += a[k].second;
        minu += a[k].first;
    }
    sec -= (c * (n - 1));

    //cout << sec << endl;

    minu += sec / 60;
    sec %= 60;

    hour = minu / 60;

    minu %= 60;
    if (hour < 10)
        cout << "0";
    cout << hour << ":";
    if (minu < 10)
        cout << "0";
    cout << minu << ":";
    if (sec < 10)
        cout << "0";
    cout << sec;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/