#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i, N) for (int i = 0; i < N; ++i)
typedef long long int LL;

class BIT
{
public:
    std::vector<LL> bit;
    void init(LL n)
    {
        bit.resize(n + 1, 0);
    }
    LL sum(LL i)
    {
        if (!i)
            return 0;
        return bit[i] + sum(i - (i & -i));
    }
    void add(LL i, LL x)
    {
        if (i >= (LL)bit.size())
            return;
        bit[i] += x;
        add(i + (i & -i), x);
    }
};

LL N;
std::vector<LL> a, a_sorted;

bool check(LL x)
{
    std::vector<LL> imos(N + 1, 0);
    BIT bit;
    LL cnt = 0;
    bit.init(2 * (N + 1));
    rep(i, N)
    {
        if (a[i] >= x)
            imos[i + 1] = 1;
        else
            imos[i + 1] = -1;
    }
    rep(i, N) imos[i + 1] += imos[i];
    for (LL i = 0; i <= N; ++i)
    {
        cnt += bit.sum(imos[i] + N);
        bit.add(imos[i] + N, 1);
    }
    return cnt >= N * (N + 1) / 4;
}

int main()
{
    in >> N;
    a.resize(N);
    rep(i, N) in >> a[i];
    a_sorted = a;
    std::sort(a_sorted.begin(), a_sorted.end());
    LL left = 0, right = N;
    while (right - left > 1)
    {
        LL mid = (left + right) / 2;
        if (check(a_sorted[mid]))
            left = mid;
        else
            right = mid;
    }
    out << a_sorted[left] << std::endl;
    return 0;
}