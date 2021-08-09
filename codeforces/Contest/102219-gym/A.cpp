#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1005;
char a[N][N], res[N][N];
using namespace std;
char findChar(char c, char direction) {
    if (c == '>' && direction == 'R') return 'v'; 
    if (c == '>' && direction == 'L') return '^';
    if (c == '<' && direction == 'R') return '^'; 
    if (c == '<' && direction == 'L') return 'v'; 
    if (c == '^' && direction == 'R') return '>'; 
    if (c == '^' && direction == 'L') return '<';
    if (c == 'v' && direction == 'R') return '<'; 
    if (c == 'v' && direction == 'L') return '>';
    if (c == '.') return '.';
}
string direc;
int n, total = 0;

void turnl() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {         
            res[i][j] = findChar(a[j][n-1-i], 'L');
        }
   for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            a[i][j] = res[i][j];
}
 
void turnr() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            res[i][j] = findChar(a[n-j-1][i], 'R');
        }
     for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            a[i][j] = res[i][j];
 
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> direc;
    for (auto c : direc){
        if (c == 'L') total -=1; else total += 1;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            cin >> a[i][j];
     
    if (total > 0) {
        total %= 4;
        while (total-- > 0) turnr();
    } else {
        total = -total;
        total %=4;
        while (total-- > 0) turnl();
    }
      for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }


}
