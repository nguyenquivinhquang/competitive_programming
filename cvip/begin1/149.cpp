#include <iostream>

using namespace std;

int main()
{
    int n, m;
    int a[2000000];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int result = 0;
    int run = 0, start = 1;
    for (int end = 1; end <= n; end++)
    {
        run += a[end];
        while (run - a[start] >= m)
        {
            run -= a[start];
            start++;
        }
        if (run == m)
        {
            for (int i = start; i <= end; i++)
                cout << a[i] << endl;
            cout<<endl;
        }
    }
    
}