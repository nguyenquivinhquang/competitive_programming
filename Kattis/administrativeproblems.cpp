//Administrative Difficulties

#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 10020;

using namespace std;
struct Car {
     string name;
     double price, pickup, km;
};
struct spyEvent {
     double time, val;
     int carid;
     string name, typeofevent, car_name;
} spy[N];

Car car[N];
int n, m, total_spy, res[N];

map<string, int> compress, carc;
map<int, string> decompress;
bool cmp(spyEvent &x, spyEvent &y) {
     if (x.name != y.name)
          return x.name < y.name;
     else
          return x.time < y.time;
}
int inconsistence(int l, int r) {
     stack<int> q;
     double total = 0;
     for (int i = l; i <= r; i++) {
          if (spy[i].typeofevent == "p") {
               if (q.size() != 0)
                    return -1;
               q.push(spy[i].carid);
               total += car[spy[i].carid].pickup;
          }
          if (spy[i].typeofevent == "r") {
               if (q.size() == 0)
                    return -1;
               int c = q.top();
               q.pop();
               total += car[c].km * spy[i].val;
          }
          if (spy[i].typeofevent == "a") {
               if (q.size() == 0)
                    return -1;
               int c = q.top();
               total += ceil(car[c].price * spy[i].val / 100.0);
          }
     }
     if (q.size())
          return -1;
     total += 0.5;
     return total;
}
void solve() {
     total_spy = 0;
     compress.clear(), decompress.clear();
     cin >> n >> m;
     for (int i = 1; i <= n; i++) {
          cin >> car[i].name >> car[i].price >> car[i].pickup >> car[i].km;
          carc[car[i].name] = i;
     }
     for (int i = 1; i <= m; i++) {
          spy[i].time = spy[i].val = 0;
          spy[i].name = spy[i].typeofevent = spy[i].car_name = "";

          cin >> spy[i].time >> spy[i].name >> spy[i].typeofevent;
          if (spy[i].typeofevent == "p") {
               cin >> spy[i].car_name;
               spy[i].carid = carc[spy[i].car_name];
          } else
               cin >> spy[i].val;
     }

     sort(spy + 1, spy + 1 + m, cmp);
     for (int i = 1; i <= m; i++) {
          if (compress[spy[i].name] == 0) {
               compress[spy[i].name] = ++total_spy;
               decompress[total_spy] = spy[i].name;
          }
     }

     int l = 1, r = 1;
     string temp = "";
     spy[m + 1].name = "";
     for (int i = 1; i <= m + 1; i++) {
          if (spy[i].name != temp) {
               if (i != 1) {
                    int id = compress[spy[i - 1].name];
                    res[id] = inconsistence(l, i - 1);
               }
               l = i;
               temp = spy[i].name;
          }
     }
     for (int i = 1; i <= total_spy; i++) {
          cout << decompress[i] << " ";
          int val = res[i];
          if (val == -1)
               cout << "INCONSISTENT";
          else
               cout << val;

          cout << endl;
     }
}

signed main() {
     // freopen("/mnt/Code/cp1/cvip/rev-adsa/input.txt", "r", stdin);
     // freopen("/mnt/Code/cp1/cvip/rev-adsa/output.txt", "w", stdout);

     ios_base::sync_with_stdio(false), cin.tie(NULL);
     int testcase;
     cin >> testcase;
     while (testcase--) {
          solve();
     }
}