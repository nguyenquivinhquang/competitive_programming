#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a[100], b[100], c[100];
    int nos = 0; // numbers of solutuion;
    int n;
    cin >> n;
    int lim = sqrt(n) + 1;
    for (int x = 0; x <= lim; x++)
    {
        for (int y = 0; y <= lim; y++)
            for (int t = 0  ; t <= lim; t++)
            {
                float z = 0.00000;
                z = sqrt(n - x * x - y * y - t * t);
                long kq = z;
                if ((x * x + y * y + kq * kq + t * t) == n)
                {
                    cout << "YES" << endl;
                    cout << x << " " << y <<" "<< t<<" " << kq << endl;
                    return 0;
                }
            }
    }
    cout << "NO" << endl;
}