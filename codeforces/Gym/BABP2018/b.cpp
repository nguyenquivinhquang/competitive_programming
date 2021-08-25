#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int get_day(int month) {
    if (month == -1) return 0;
    if (month == 1 || month==3 || month==5||
        month==7||month==8||month==10||month==12) return 31;
    if (month == 2) return 28;
    return 30;
}
bool isSmaller(pp x, pp y) {
    if (x.first != y.first) return x.first < y.first;
    if (x.second > y.second) return false;
    return true;
}
int day_distance(pp x, pp y) {
    // cout << x.first << " " << y.first << endl;
    if (isSmaller(x, y)) {
        if (x.first == y.first) return y.second - x.second;
        int res = get_day(x.first++) - x.second + y.second;
        for (int i = x.first; i < y.first; i++) res += get_day(i);
        return res;
    }
    int res = get_day(x.first) -x.second;
    for (int i = x.first + 1; i <= 12; i++) res += get_day(i);
    for (int i =1; i < y.first; i++) res += get_day(i);
    res += y.second; return res;
}
bool  cmp(pp x, pp y) {
    if (x.first == y.first) return x.second < y.second;
    return x.first < y.first;
}
pp sp(string x) {
    int month = 0, day = 0;
    bool check =true;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '-'){
             check = false;
             continue;
        }
        if (check) {
            month = month * 10 + (x[i] -'0');
        } else day = day * 10 + (x[i] -'0');
    }
    return {month, day};
}
int n; 
vector<pp> a, b;
pp dm;
signed main() {
    dm = {10, 28};
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        string name, temp; cin >> name >> temp;
        a[i] = sp(temp);
    }
    // for (auto v : a) cout << v.first << endl;
    sort(a.begin(), a.end(), cmp);
    // for (auto v : a) if (v > dm) b.push_back(v);
    // for (auto v : a) if (v <= dm) b.push_back(v);
    // a = b;
    a[0] = a[n]; int i = 0;
    int res = -1; pp ans = {-1, -1};
    for (int month = 1; month <= 12 ; month++) 
        for (int day = 1;  day <= get_day(month); day++ ){
        pp cur_day = {month, day};
        // if (month == 10 && day == 27) 
        //     cout << "OK";
        while (i < n && isSmaller(a[i+1],cur_day)) i++;
        int dis = day_distance(a[i], cur_day);
        if (dis > res) {
            res = dis;
            ans = cur_day;
        
        } else if (dis == res) {
            int x = day_distance(dm, cur_day);
            int y =  day_distance(dm, ans);
            if (x < y ) 
                ans = cur_day;
        }
    }

    int month = ans.first, day = ans.second;
    if (month < 10) cout << 0;
    cout << month << "-";
    if (day < 10) cout << 0;
    cout << day;
}
