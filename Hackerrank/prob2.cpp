/*
    Given a grid rectangle w x h, calculate the maxmimum area after each step removing a vertival line or a horizontal line;
    example: w = 4, h = 4; isVertical = {0, 1}, distance = {3, 1}
    first: remove the horizontal at pos 3, the maxmimum area can have is 3x4 -> 12
    first: remove the vertical at pos 1, the maxmimum area can have is 3x3 -> 9, all the area can have are: 1x1, 3x3, 1x3, 3x1
    

*/

#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
set<int> vertical, horizontal;
multiset<int, greater<>> dis_ver, dis_hori;
int n, m;
int update_vertival(int i) {
    if (i == 0 || i == n ) return *dis_ver.begin();
    auto it = vertical.lower_bound(i);
    if (*it == i) return *dis_ver.begin();
    int up = *it; it--;
    int down = *it;
    auto it_dis = dis_ver.find(up - down);
    dis_ver.erase(it_dis);
    vertical.insert(i);
    dis_ver.insert(abs(up - i)); dis_ver.insert(abs(i - down));
    return  *dis_ver.begin();
}
int update_horizontal(int i) {
    if (i == 0 || i == m ) return *dis_hori.begin();
    auto it = horizontal.lower_bound(i);
    if (*it == i) return *dis_hori.begin();
    int up = *it; it--;
    int down = *it;
    auto it_dis = dis_hori.find(up - down);
    dis_hori.erase(it_dis);
    horizontal.insert(i);
    dis_hori.insert(abs(up - i)); dis_hori.insert(abs(i - down));
    return  *dis_hori.begin();
}
vector<long> getMaxArea(int w, int h, vector<bool> isVertical, vector<int> distance) {
    vector<long> res;
    int n = w, m = h;
    vertical.insert(n); vertical.insert(0);
    horizontal.insert(m); horizontal.insert(0);

    dis_ver.insert(n); dis_hori.insert(m);
    long x,y;
    for (int i = 0; i < isVertical.size(); i++) {
        if (isVertical[i] == true) 
             update_vertival(distance[i]);
        else  update_horizontal(distance[i]);
        x = *dis_ver.begin(); y = *dis_hori.begin();
        res.push_back(x * y);    
        cerr << x * y << endl;
    }
    
    return res;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int w = 4, h = 4;
    vector<bool> isVertical = {0, 1};
    vector<int> distance = {3, 1};
    getMaxArea(w, h , isVertical, distance);

}
