#include  < bits / stdc++.h>
#define  N 100
using namespace std;
int n, a[N], b[N], m, c[N], k;
void q1()
{
        cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n / 2);
    sort(a + n / 2 + 1, a + 1 + n, greater<>());
}
void q2()
{
        int i = 1;
        cin >> m;
        b[0] = - 1e9;
        while (i <= m)
    
    {
                cin >> b[i];
                if  (b[i] >= b[i - 1])
            i++;
                else         
        {
                        cout << "input again";
        }
            
    }
}
void q3()
{
        k = 1;
        int i = 1, j = 1;
        while (i <= n / 2 && j <= m)
        if  (a[i] < b[j])
            c[k++] = a[i++];
            else             c[k++] = b[j++];
        while (i <= n / 2)
        c[k++] = a[i++];
        while (j <= m)
        c[k++] = b[j++];
        k--;
}
void q4()
{
        if  (k % 2 == 0)
        cout << (c[k / 2] + c[k / 2 + 1]) / 2;
        else         cout << c[k / 2 + 1];
}
int main()
{

        q1();
        q2();
        q3();
        q4();
    for (int i = 1; i <= k; i++)
        cout << c[i] << " ";
}