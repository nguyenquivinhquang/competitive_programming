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
    vector<int> p[100];
};

data b[maxn], c[maxn];

vector<bool> isPrime(maxn + 1, true), prime(maxn + 1, false);

vector<int> snt(maxn);
vector<int> ssnt;
int count_snt = 0, res = 0, start = 0;

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
                prime[snt[j]] = true;
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
    }
}

void debug(int t)
{
    int i = 1;
    while (c[i].p.size() == 1)
    {
        for (auto it = c[i].p.begin(); it != c[i].p.end(); it++)
            prime[*it] = false;
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
    ofstream write1("debugprime.txt");
    for (int x = 1; x <= t; x++)
    {
        //write << a[x] << ":  " << el;
        for (auto i = c[x].p.begin(); i != c[x].p.end(); i++)
            write1 << *i << " ";
        write1 << el;
    }
    write1.close();
    ofstream write2("prime.txt");
    for (int i = 1; i <= maxn; i++)
        if (prime[i] == true)
            write2 << i << " ";
}
int quangcute(int t)
{
    int res_n = 1;
    c[1] = b[1];
    for (int i = 1; i <= t; i++)
        if (c[res_n].p != b[i].p)
        {
            res_n++;
            c[res_n] = b[i];
            }
    for (int i = 1; i <= res_n; i++)
        if (c[i].p.size() == 1)
            ssnt.insert(ssnt.end(), c[i].p.begin(), c[i].p.end()), res++;

    return res_n;
}

bool tt(data x, data y)
{
    if (x.p.size() < y.p.size())
        return true;
    if (x.p.size() > y.p.size())
        return false;
    if (x.p < y.p)
        return true;
    else
        return false;
}

void dequi(vector<int> x, vector<int> y, int pos, int sl) // sl la sl so
{
    res = max(res, sl);
    x.insert(x.end(), y.begin(), y.end());
    for (int i = pos - 1; i >= start; i--)
    {
        bool check = true;
        vector<int>::iterator it;
        for (auto j = x.begin(); j != x.end(); j++)
        {
            it = find(c[i].p.begin(), c[i].p.end(), *j);
            if (it != c[i].p.end())
            {
                check = false;
                break;
            }
        }

        if (check == true)
        {
            dequi(x, c[i].p, i, sl + 1);
        }
    }
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
    sort(b, b + t + 1, tt);

    int temp = quangcute(t);
    start = res;
    //aaa(temp);
    vector<int> t1, t2;
    debug(temp);
    dequi(ssnt, t2, temp + 1, 0);
    //debug(temp);
    cout << res;
}
