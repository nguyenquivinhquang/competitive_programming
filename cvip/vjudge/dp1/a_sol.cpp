#include <bits/stdc++.h>

using namespace std;

const int MIN_INT = -0x7F7F7F7F;

int main()
{
    int t, n, s;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++)
    {
        scanf("%d", &n);

        int max = MIN_INT, sum = MIN_INT;
        int left = 1, start = 1, end = 1;
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &s);
            if (sum + s < s)
                sum = s, left = i;
            else
                sum += s;
            if (sum > max || (sum == max && i - left > end - start))
            {
                max = sum;
                start = left;
                end = i;
            }
        }

        if (max <= 0)
            printf("Route %d has no nice parts\n", k);
        else
            printf("The nicest part of route %d is between stops %d and %d\n", k, start, end + 1);
    }

    return 0;
}
