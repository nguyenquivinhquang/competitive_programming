#include <bits/stdc++.h>
#define ll long long
#define maxn 1000
using namespace std;
struct trie
{
    bool last;
    char n[27];
};
int main()
{
    int f_value = 10;
    int *p = new int;
    p = &f_value;
    cout << *p << endl;
    *p = 20;
    cout << f_value;
}