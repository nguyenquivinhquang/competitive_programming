#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#define el '\n'
#define mod %
#define ll long long
#define maxn 5000

using namespace std;

int a[maxn];
struct data
{
    vector<int> p, q;
    int large;
};
struct data2
{
    vector<int>p[100];
};

data b[maxn],c[maxn];

vector<bool> isPrime(maxn + 1, true),prime(maxn+1,false);

vector<int> snt(maxn);
int count_snt = 0;
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
void eratos()
{
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= maxn; ++i)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= maxn; j += i)
                isPrime[j] = false;
        }
    }
    //ofstream write("prime.txt");
    for (int i = 1; i <= maxn; i++)
        if (isPrime[i] == true)
        {
            count_snt++;
            //write << "a[" << count_snt << "]=" << i << ", ";
            snt[count_snt] = i;
        }
}
void tries()
{
    vector<int> a(5, 0);
    a.push_back(3);
    a.push_back(1), a.push_back(1212), a.push_back(2);
    for (auto i = a.begin(); i != a.end(); i++)
        cout << *i << el;
    vector<int>::iterator it;
    it = find(a.begin(), a.end(), 12321);
    cout << it - a.begin() + 1;
}
void pre(int t)
{
    ofstream write("debugprime.txt");
    int n;
    vector<int>::iterator it;
    for (int i = 1; i <= t; i++)
    {
        n = a[i];
        for (int j = 1; j <= count_snt; j++)
        {
            if (snt[j] > n)
                break;
            if (n % snt[j] == 0)
            {
                prime[snt[j]]=true;
                it = find(b[i].p.begin(), b[i].p.end(), snt[j]);
                if (it == b[i].p.end())
                    b[i].p.push_back(snt[j]);
                while (n % snt[j] == 0)
                    n /= snt[j];
            }
        }
        b[i].large = 1;
        b[i].q = b[i].p;
        //debug

        write << a[i] << ": ";
        for (auto j = b[i].p.begin(); j != b[i].p.end(); j++)
            write << *j << " ";
        write << el;
    }
}
void check(int x, int y)
{
    //x la goc, t la dg xet
    bool verify = true;
    vector<int>::iterator it;

    for (auto i = c[x].p.begin(); i != c[x].p.end(); i++)
    {
        it = find(c[y].p.begin(), c[y].p.end(), *i);
        if (it != c[y].p.end())
        {

            return;
        }
    }
    verify = false;
    if (c[x].large < 2)
        verify = true;
    if (verify == true)
    {
        c[x].q.clear();
        c[x].q.insert(c[x].q.end(), c[x].p.begin(), c[x].p.end());
        c[x].q.insert(c[x].q.end(), c[y].p.begin(), c[y].p.end());
        c[x].large = 2;
    }

    for (auto i = c[x].p.begin(); i != c[x].p.end(); i++)
    {
        it = find(c[y].q.begin(), c[y].q.end(), *i);
        if (it != c[y].q.end())
        {
            return;
        }
    }
    if (c[y].large + 1 > c[x].large)
    {
        c[x].q.clear();
        c[x].q.insert(c[x].q.end(), c[x].p.begin(), c[x].p.end());
        c[x].q.insert(c[x].q.end(), c[y].q.begin(), c[y].q.end());
        c[x].large = c[y].large + 1;
    }
    else if (c[y].large + 1 == c[x].large && c[x].q.size() > c[y].q.size())
    {
        c[x].q.clear();
        c[x].q.insert(c[x].q.end(), c[x].p.begin(), c[x].p.end());
        c[x].q.insert(c[x].q.end(), c[y].q.begin(), c[y].q.end());
        c[x].large = c[y].large + 1;
    }
}
void debug(int t)
{
    int i=1;
    while (c[i].p.size()==1)
    {
        for (auto it = c[i].p.begin(); it != c[i].p.end(); it++)
            prime[*it]=false;
        i++;
    }
    
    ofstream write("debug_coprime1.txt");
    for (int x = 1; x <= t; x++)
    {
        //write << a[x] << ":  " << el;
        for (auto i = c[x].q.begin(); i != c[x].q.end(); i++)
            write << *i << " "; //debug
        write << " :" << c[x].large << el << "-----------" << el;
    }
    write.close();
    ofstream write1 ("debugprime.txt");
    for (int x = 1; x <= t; x++)
    {
        //write << a[x] << ":  " << el;
        for (auto i = c[x].p.begin(); i != c[x].p.end(); i++)
            write1 << *i << " "; 
        write1<<el;
    }
    write1.close();
    ofstream write2 ("prime.txt");
    for (int i=1;i<=maxn;i++)
        if (prime[i]==true) write2<<i<<" ";
}
int quangcute(int t)
{
    int res_n=1;
    c[1]=b[1];
    for (int i=1;i<=t;i++)
    if (c[res_n].p!=b[i].p)
    {
        res_n++;
        c[res_n]=b[i];
    }
    return res_n;
}
void aaa(int t)
{
    for (int i = 1; i <= t; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            check(i, j);
        }
    }
}
bool tt(data x, data y)
{
    if (x.p.size() < y.p.size())
        return true;
    if (x.p.size() > y.p.size())
        return false;
    if (x.p<y.p) return true; else return false;
}


int main()
{
    int t;
    eratos();
    cin >> t;
    a[0] = 0;
    for (int i = 1; i <= t; i++)
    {
        cin >> a[i];
    }
    sort(a, a + t + 1);
    pre(t);
    sort(b,b+t+1,tt);
    
    int temp=quangcute(t);

    //aaa(temp);

    aaa(temp);
    //debug(temp);
    int res = 0;
    for (int i = 1; i  <= temp; i++)
    {

        res = max(res, c[i].large);
    }
    cout << res<<" hihiquangu "<<temp;
} 
