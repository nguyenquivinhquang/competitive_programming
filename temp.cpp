#include<bits/stdc++.h>

using namespace std;
const  int N = 100;
int  n;
double heat[N][N];
double calculate(int x, int y) {
    if (x == n + 1 || y == 0 ) {
        if (x == n+1 && y == 0) return (heat[x-1][y] + heat[x][y + 1])/2.0;
        if (x == n+1) return (2.0 * heat[x - 1][y] + heat[x][y + 1] + heat[x][y-1]) / 4.0;
        if (y == 0 ) return (2.0 * heat[x][y + 1] + heat[x+1][y] + heat[x-1][y]) / 4.0;
    } 
    // if (x == n+1 && y == 0) return (heat[x-1][y] + heat[x][y + 1])/2.0;
    
    return (heat[x+1][y] + heat[x-1][y] + heat[x][y-1] + heat[x][y + 1]) / 4;
}
int temp[N][N];
int direction = 1;
void show() {
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            cout << heat[i][j] << " ";
        }
        cout << "\n";
    }
}
int preX = 1;
void getXY(int &x, int &y) {
    
    if ((x == n + 1 || x == 1) && preX != x) {
        direction *= -1; // become -1;
        y--;
        preX = x;
        return;
    }
    preX = x;
    x = x + direction;
}
double solve1() {
    double err = -1;
    int i = 1, j = n;
    while (i > 0 || j >= 0) {
        double pre = heat[i][j];
        heat[i][j] = 1.2 * calculate(i, j) + (1 - 1.2) * heat[i][j];
        err = max(err, abs(heat[i][j] - pre) / heat[i][j]);
        if (i == 1 && j == 0) break;
        getXY(i, j);
        cout << n -  i + 1 << " " << n - j + 1 << "\n";
    }
    return err;
}
double solve2() {
    double err = -1;
    for (int i = 1; i <= n+1; i++) {
        for (int j = n; j >= 0; j--) {
            double pre = heat[i][j];
            heat[i][j] = 1.2 * calculate(i, j) + (1 - 1.2) * heat[i][j];
            err = max(err, abs(heat[i][j] - pre) / heat[i][j]);
        }
    }
    return err;
}
signed main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            cin >> heat[i][j];
            // cout << heat[i][j] << " ";
        }
        // cout << "\n";
    }
    for (int ite = 1; ite < 2; ite++) {
        
        cout << "Iteration " << ite << "\n";
        double err = solve1();
        // }
        // for (int i = 1; i <= n+1; i++) 
        //     for (int j = 0; j <= n; j++) heat[i][j] = temp[i][j];
        show();
        cout << "------\n";
        if (err < 0.01) break;
    }
    
}