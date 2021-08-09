#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<bool> mark(10001, true);

void primecal()
{

    mark[0] = mark[1] = false;

    for (int i = 2; i <= 10001; i++)
    {
        if (mark[i])
            for (int j = i * 2; j <= 10001; j += i)
                mark[j] = false;
    }
    mark[1] = false;
}
bool exponential(int x)
{
    int i = 0;
    while (pow(5, i) != x)
    {
        i++;
        if (pow(5, i) > x)
            return false;
    }
    return true;
}
bool sochinhphuong(float n)
{

    if ((float)sqrt(n) - (int)sqrt(n) == 0)
        return true;
    return false;
}
int main()
{
    int t, n;
    primecal();

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int res_scp = 0, res_prime = 0, res_squareroot = 0;
        int q = 0, w = 0, e = 0;
        int a = 0;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            if (sochinhphuong(a) == true)
                res_scp++;
            else
            {
                q = max(q, res_scp);
                res_scp = 0;
            }
            if (mark[a] == true)
                res_prime++;
            else
            {
                w = max(w, res_prime);
                res_prime = 0;
            }
            if (exponential(a) == true)
                res_squareroot++;
            else
            {
                e = max(e, res_squareroot);
                res_squareroot = 0;
            }
        }
        q = max(q, res_scp); w = max(w, res_prime); e = max(e, res_squareroot);
        cout << q << " " << e << " " << w << endl;
    }
}