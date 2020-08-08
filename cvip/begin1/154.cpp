#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int main()
{
    int a[31];
    int trace[31];
    int kq[31];
    int n = 1;
    int max_res = 1;

    while (cin >> a[n])
    {
        trace[n] = 1;
        n++;
    }
    n--;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 1; j--)

            if (trace[j] % 2 == 0)
            {
                if (a[j] > a[i])
                    trace[i] = max(trace[i], trace[j] + 1);
            }
            else
            {
                if (a[j] < a[i])
                    trace[i] = max(trace[i], trace[j] + 1);
            }
        max_res = max(max_res, trace[i]);
    }
    int i;
    for (i = 1; i <= n; i++)
    {
        if (trace[i] == max_res)
        {
            break;
        }
    }
    kq[max_res] = a[i];
    n = max_res;
    int temp = a[i];
    for (int j = i; j >= 1; j--)
    {
        
        if (trace[j] == max_res )
            if (max_res % 2 != 0)
            {
                if (a[j] < kq[max_res+1])
                {
                    kq[max_res] = a[j];
                    temp = a[j];
                }
            }
            else
            {
                if (a[j] > kq[max_res+1])
                {
                    kq[max_res] = a[j];
                    temp = a[j];
                }
            }
      
        if (trace[j] == max_res - 1)
            if (max_res % 2 == 0)
            {
                if (a[j] < temp)
                {
                    max_res--;
                    kq[max_res] = a[j];
                    temp = a[j];
                }
            }
            else
            {
                if (a[j] > temp)
                {
                    max_res--;
                    kq[max_res] = a[j];
                    temp = a[j];
                }
            }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << kq[i] << " ";
    }
}