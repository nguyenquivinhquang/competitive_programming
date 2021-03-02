#include <bits/stdc++.h>
using namespace std;
const int N = 205;
typedef pair<int, int> pp;
char a[N][N], c;
int n, m;

vector<char> res;
queue<char> q;

char check(pp ss, pp ee) {
    int num0 = 0, num1 = 0;
    for (int i = ss.first; i <= ee.first; i++)
        for (int j = ss.second; j <= ee.second; j++) {
            if (a[i][j] == '1') num1++;
            if (a[i][j] == '0') num0++;
            if (num1 * num0 != 0) return 'D';
        }
    if (num0 == 0) return '1'; else return '0';
}
void convertBtoD(pp ss, pp ee) { 
    if (ss.first > n || ss.second > m || ee.first > n || ee.second > m || ss.first < 1 || ee.first < 1 || ss.second < 1 || ee.second < 1) return;
   
    char t = check(ss, ee);
    res.push_back(t);
    if (t != 'D') return;
    if (ss == ee) return;
    pp mid = {(ss.first + ee.first) /2 , (ss.second + ee.second ) / 2};

    convertBtoD(ss, mid);
    if (mid.second + 1 <= ee.second )
        convertBtoD({ss.first, mid.second + 1}, {mid.first, ee.second}); // upright
    if (mid.first + 1 <= ee.first) 
        convertBtoD({mid.first + 1, ss.second}, {ee.first, mid.second}); //downleft
    if (mid.first + 1  <= ee.first && mid.second + 1 <= ee.second)
        convertBtoD({mid.first + 1, mid.second + 1}, {ee.first, ee.second}); //dowright
}
void fill(pp ss, pp ee, char d) {
    for (int i = ss.first; i <= ee.first; i++)
        for (int j = ss.second; j <= ee.second; j++) {
            a[i][j] = d;
        }
}
void convertDtoB(pp ss, pp ee) {
    if (ss.first > n || ss.second > m || ee.first > n || ee.second > m || ss.first < 1 || ee.first < 1 || ss.second < 1 || ee.second < 1) return;
    if (q.size() == 0) return;
    char c = q.front();    

    q.pop();
    if (c != 'D'){ 
        fill(ss, ee, c);
        return;
    }
    pp mid = {(ss.first + ee.first) / 2 , (ss.second + ee.second ) / 2};
    convertDtoB(ss, mid); //upleft
    if (mid.second + 1 <= ee.second )
        convertDtoB({ss.first, mid.second + 1}, {mid.first, ee.second}); // upright
    if (mid.first + 1 <= ee.first) 
        convertDtoB({mid.first + 1, ss.second}, {ee.first, mid.second}); //downleft
    if (mid.first + 1  <= ee.first && mid.second + 1 <= ee.second)
        convertDtoB({mid.first + 1, mid.second + 1}, {ee.first, ee.second}); //dowright
}
signed main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        cin >> c;
        if (c == '#') break;
        cin >> n >> m;        
        if (c == 'B') {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    cin >> a[i][j];
            convertBtoD({1, 1}, {n, m});
            cout << "D" << right << setw(4) << n << right << setw(4) << m << endl;
            int t = 1;
            for (int i = 0; i < res.size(); i++) {
                cout << res[i];
                if ((i + 1 ) % 50 == 0) cout << "\n";
                t = i + 1;
            }
            // t--;
            if (t % 50 != 0) cout << "\n";
            res.clear();
        }
        else {
            string input;
            cin >> input;
            for (int i = 0; i < input.length(); i++)
                q.push(input[i]);
            convertDtoB({1, 1}, {n, m});
            cout << "B" << right << setw(4) << n << right << setw(4) << m << endl;
            int t = 1;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++){
                    cout << a[i][j];
                    if ( t % 50 == 0 ) cout << "\n";
                    t++;
                }
            t--;
            if (t % 50 != 0) cout <<"\n";
        }

    }
    

}