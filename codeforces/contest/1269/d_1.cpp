#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int N;
    cin >> N;
    ll b = 0, w = 0;
    cout<<endl<<"B"<<" "<<"W"<<endl;
    for (int i = 0; i < N; i++)
    {
        ll A;
        cin >> A;
        if (i%2==1 )
            b += A / 2, w += (A + 1) / 2;
        else
            b += (A + 1) / 2, w += A / 2;
        cout<<b<<" "<<w<<endl;
    }
    cout << min(b, w) << endl;
    return (0);
}
