#include <bits/stdc++.h>
#define ll long long
#define mod %
#define maxn 90000

using namespace std;
vector<int> snt(maxn);
int count_snt = 0, sm[maxn],temp[maxn];
int N = 500000, du = 0,count_temp;

void eratos()
{
    vector<bool> isPrime(N + 1, true);
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

    
    //cout << count_snt;
}
void prime_factor(int a)
{
    int c=sqrt(a), t=a;
    if (a==1) return;
    for (int i = 1; i <= count_snt; i++)
    {
     
        if (snt[i] >a)
            break;
        c=sqrt(a);
        if (a>10)
            if (snt[i]>c+2) break;

        while (a mod snt[i] == 0)
        {
            count_temp++;
            temp[count_temp]=snt[i];
            a = a / snt[i];
        }
    }
    if (a!=1)
    {
           count_temp++;
            temp[count_temp]=a;
    }

  
}
void pre()
{
    sort(temp,temp+count_temp+1);
    int t=0;
    sm[0]=0;
    for (int i=1;i<=count_temp;i++)
    if (temp[i]==temp[i-1]) sm[t]++; else
    {
        t++;
        sm[t]=1;
    }
    count_temp=t;
    
}
int main()
{
    eratos();
    int a, b, t;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        count_temp=0;
        prime_factor(a);
        prime_factor(b);
        ll res = 1;
        if (du == 0) du = 1;
        pre();
        for (int i = 1; i <= count_temp; i++)
            res = (sm[i] * 2 + 1) * res;
        cout << res << "\n";
    }
}