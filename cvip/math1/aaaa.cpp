#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fastio()                      \
    ;                                 \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define meo                                                        \
    ;                                                              \
    struct st                                                      \
    {                                                              \
        long long data[MN];                                        \
        long long M[ML][MN];                                       \
        int n;                                                     \
        void read(int _n)                                          \
        {                                                          \
            n = _n;                                                \
            for (int i = 0; i < n; ++i)                            \
            {                                                      \
                scanf("%lld", data + i);                           \
                M[0][i] = data[i];                                 \
            }                                                      \
            data[n] = M[0][n] = 1;                                 \
        }                                                          \
        void build()                                               \
        {                                                          \
            int k = 1;                                             \
            while ((1 << k) <= n)                                  \
            {                                                      \
                int d = 1 << (k - 1);                              \
                for (int i = 0; i + 2 * d <= n + 1; i++)           \
                    M[k][i] = __gcd(M[k - 1][i], M[k - 1][i + d]); \
                k++;                                               \
            }                                                      \
        }                                                          \
        long long query(int b, int e)                              \
        {                                                          \
            int x = 0;                                             \
            while (b + (1 << x) <= e + 1)                          \
                x++;                                               \
            x--;                                                   \
            int d = 1 << x;                                        \
            return __gcd(M[x][b], M[x][e - d + 1]);                \
        }                                                          \
    };
#define mew                                            \
    ;                                                  \
    st tree;                                           \
    void solve()                                       \
    {                                                  \
        int n;                                         \
        scanf("%d", &n);                               \
        tree.read(n);                                  \
        tree.build();                                  \
        long long best = 1;                            \
        for (int i = 0; i < n; ++i)                    \
        {                                              \
            long long need = tree.data[i];             \
            int j = i;                                 \
            while (j < n)                              \
            {                                          \
                int lo = j, hi = n - 1;                \
                while (lo < hi)                        \
                {                                      \
                    int mid = (lo + hi + 1) >> 1;      \
                    if (tree.query(i, mid) == need)    \
                    {                                  \
                        lo = mid;                      \
                    }                                  \
                    else                               \
                    {                                  \
                        hi = mid - 1;                  \
                    }                                  \
                }                                      \
                best = max(best, need * (lo - i + 1)); \
                j = lo + 1;                            \
                if (j < n)                             \
                    need = tree.query(i, j);           \
            }                                          \
        }                                              \
        printf("%lld\n", best);                        \
    }                                                  \
    int main()                                         \
    {                                                  \
        fastio();                                      \
        int T;                                         \
        scanf("%d", &T);                               \
        while (T--)                                    \
        {                                              \
            solve();                                   \
        }                                              \
    }
#define meow                    \
    ;                           \
    typedef long long ll;       \
    const int MN = 100000 + 10; \
    const int ML = 20;
using namespace std;
meow;
meo;
mew;