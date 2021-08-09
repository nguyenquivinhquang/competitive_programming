#include <bits/stdc++.h>
#define ll long long
#define maxn 1000000
#define el '\n'
using namespace std;

vector<int> snt(maxn);
int count_snt = 0, count_pf[maxn];
int N = 1000000, du = 0,count_temp;

vector<bool> isPrime(N + 1, true);
    
void eratos()
{
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
    //ofstream write("prime.txt");
    for (int i = 1; i <= N; i++)
        if (isPrime[i] == true)
        {
            count_snt++;
            //write << "a[" << count_snt << "]=" << i << ", ";
            snt[count_snt] = i;
        }

    
    
}
void debug()
{
    /*ofstream write ("debug_examtime.txt");
    for (int i=1;i<=count_snt;i++)
        write<<snt[i]<<" stt: "<<i<<el;
    */
   for (int i=1;i<=10;i++)
    cout<<count_pf[i]<<el;
}
void pre_process()
{
    count_pf[1]=0;
    for (int i=2;i<=1000000;i++)
    {
        if (isPrime[i]==true)
        {
            count_pf[i]=count_pf[i-1]+1;
        } else
        {
            int temp=i;
            count_pf[i]=count_pf[i-1];
            int j=2;
            while (j<=sqrt(temp))
            {
                while (temp%j==0)
                {
                    temp=temp /j;
                    count_pf[i]++;
                }
                j++;
            }
            if (temp>1) count_pf[i]++;
        }
        
    }
}
int main()
{
    eratos();
    
    pre_process();
    //debug();
    int testcase,temp;
    cin>>testcase;
    while (testcase--)
    {
        cin>>temp;
        cout<<count_pf[temp]<<el;
    }
    
    
}