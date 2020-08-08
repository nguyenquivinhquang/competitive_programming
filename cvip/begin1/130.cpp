#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int a = n; a >= 0; a--)
        for (int b = a; b >= 0; b--)
            for (int c = b; c >= 0; c--)
                for (int d = c; d >= 0; d--)
                    for (int e = d; e >= 0; e--)
                        if (a+b+c+d+e==n) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
}