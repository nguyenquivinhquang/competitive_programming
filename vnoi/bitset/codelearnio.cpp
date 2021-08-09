//https://codelearn.io/learning/thu-vien-chuan-cpp/691102
#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;

int countOperations(int n) //66
{
    bitset<20> bs(n);
    return bs.count();
}
std::vector<int> checkActivity(int n) //67
{
    vector<int> temp;
    while (n > 0)
    {
        temp.push_back(n % 2);
        n /= 2;
    }
    return temp;
}
char convertChar(char ch)
{
    bitset<7> foo(ch);
    foo.flip();
    return char(foo.to_ulong());
}
int main()
{
    int testcase;
    checkActivity(12);
    cout << 3|1;
}