#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
string str;
int n;
signed main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >> n >> str;
    int digit = 0,x = 0 , y = 0;
    while (y >= 0) {
//        cout << x << " " << y << endl;
        y = (n - 2 * x) / 3;
        if (y * 3 + 2 * x == n && y >= 0) break;
        x++;
    }

    for (char c : str) {
        if (digit >= 2) {
            if (x > 0) {
                cout << "-";
                digit = 0, x--;
            } else if (digit == 3) {
                cout << "-";
                digit =0, y--;
            }
        }
        cout << c;
        digit++;
    }
}
