#include <bits/stdc++.h>
   
using namespace std;
   
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=(a); i<=b; i++)
 
typedef long long LL;
 
int main()
{
    int ax,bx,a,b;
    cin >> ax >> bx;
    //bat buoc
    a = min(ax,bx);
    b = max(ax,bx);
     
    int F[b+1][b+1];
     
    FOR(i,1,a)
    {
        FOR(j,i,b)
        {
            //Tinh F[i,j]
            if(i == j)
            {
                F[i][j] = F[j][i] = 1;
            }else{
                if(j%i == 0)
                {
                    F[i][j] = F[j][i] = j/i;
                }else{
                    int Min = j;
                     
                    //Giu j chay i
                    FOR(h,1,i/2)
                    {
                        int kq = F[h][j] + F[i-h][j];
                        if(kq < Min)
                            Min = kq;
                    }
                     
                    FOR(c,1,j/2)
                    {
                        int kq = F[i][c] + F[i][j-c];
                        if(kq < Min)
                            Min = kq;
                    }
                     
                    F[i][j] = F[j][i] = Min;
                }
            }
        }
    }
    cout << F[a][b];
    return 0;
}
 