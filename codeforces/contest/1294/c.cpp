#include <bits/stdc++.h>
#define maxn 1001
#define ll long long
#define mod %
#define el '\n'
#define Y "YES"
#define N "NO"
using namespace std;
bool check_nguyen(double x)
{

    int t = x;
    if (x - t > 0)
        return false;
    return true;
}
bool cal(double n)
{
    double c;
    int limit = pow(n, 1.0 / 2.0) + 3;
    for (int i = 2; i <= pow(n,1.0/3.0)+1; i++)
        for (int j = i + 1; j <= limit && check_nguyen(n/i)==true ; j++)                                        
        {
            if (i*j>n) break;
            c = n / (i * j);
            if (check_nguyen(c) == true && c != i && c != j&& c>j)
            {
                ll C = c;
                cout << Y << endl
                     << i << " " << j << " " << C << endl;
                return true;
            }
        }
    return false;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        double n;
        cin >> n;
        if (cal(n) == false)
            cout << "NO" << "\n";
    }

    //11 5237 17359
    
}