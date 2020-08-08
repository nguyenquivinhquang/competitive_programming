#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a,testcase;
    cin>>testcase;

    for (int i=1;i<=testcase;i++)
    {
        int round = 0, survival = 0, winner = 1;
        cin>>n;
        while (1!=0)
        {
            round++;
            a = log2(n);
            int l = n - pow(2, a);
            winner=2*l+1;
            //debug
            //cout<<round<<" "<<winner<<endl;
            if (n==winner) 
            {
                cout<<"Case "<<i<<": "<<round-1<<" "<<n<<endl;
                break;
            }
            n=winner;
        }
    }
}