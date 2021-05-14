// Conversation Log

#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, string>

const int N = 200005;

using namespace std;
map<string, int> user, compress;
map<int, string> decompress;
vector<pp> res;
int n, total = 0, total_compress = 0, appear[N];
set<int> us[N];
bool cmp(pp a, pp b) {
     if (a.first != b.first)
          return a.first > b.first;
     return a.second < b.second;
}
void split(string &x) {
     if (!x.size()) return;
     vector<string> a;
     string temp = "";
     for (int i = 0; i < x.length(); i++) {
          if (x[i] == ' ') {
               a.push_back(temp);
               temp = "";
          } else
               temp = temp + x[i];
     }
     a.push_back(temp);
     int id = user[a[0]];

     if (id == 0)
          user[a[0]] = ++total, id = total;
     for (int i = 1; i < a.size(); i++) {
          int j = compress[a[i]];
          if (j == 0) {
               compress[a[i]] = ++total_compress;
               decompress[total_compress] = a[i];
               j = total_compress;
          }
          us[j].insert(id);
          appear[j]++;
     }
}
signed main() {
     ios_base::sync_with_stdio(false), cin.tie(NULL);
     memset(appear, 0, sizeof(appear));
     //freopen("/mnt/Code/cp1/cvip/rev-string/input.txt", "r", stdin);
     string temp;
     cin >> n;
     while (getline(cin, temp)) {
          split(temp);
     }
     for (int i = 1; i <= total_compress; i++)
          if (us[i].size() == total) {
               res.push_back({appear[i], decompress[i]});
          }
     sort(res.begin(), res.end(), cmp);
     if (res.size() == 0)
          cout << "ALL CLEAR";
     else
          for (auto v : res) {
               cout << v.second << "\n";
          }
}