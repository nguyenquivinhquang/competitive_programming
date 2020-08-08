#include <bits/stdc++.h>

using namespace std;
string a;
int main()
{
   
    cin >> a;
    int t1, t2, res;
    for (int i = 1; i < a.length(); i++)
    {
        if (a[i] == a[i - 1])
        {
            t1 = a[i - 1], t2 = a[i + 1];
            res = 97;
            while (res == t1 || res == t2)
                res++;
            a[i] = res;
        }
    }
    cout << a;
}
// problem la mot su si nhuc toi anh Hung