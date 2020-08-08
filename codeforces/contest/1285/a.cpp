#include <bits/stdc++.h>
#define el '\n'
#define mod &
using namespace std;

int main()
{
    char t;
    int n;
    int count_l=0, count_r=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>t;
        if (t=='L') count_l--; else count_r++;       
    }
    cout<<abs(count_l-count_r)+1;
}