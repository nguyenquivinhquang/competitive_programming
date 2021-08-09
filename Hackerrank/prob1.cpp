#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;
/*
Given an array of non-negative integers, count the number of unordered pairs of array elements such that their bitwise AND is a power of 2.
For example, let's say the array is arr = [10, 7, 2, 8, 3], and let '&' denote the bitwise AND operator. 
There are 6 unordered pairs of its elements that have a bitwise AND.


*/
using namespace std;
long countPairs(vector<int> arr) {
    vector<int> trace(5000, 0);
    unordered_map<int, int> a;
    for (auto v : arr) {
        a[v]++;
    }
    long res = 0;
    int n = a.size();
    for (int i = 0; i < 4096; i++) {
        if (a[i] == 0) continue;
        for (int j = i; j <= 4096; j++) {
            if (__builtin_popcountll(i & j) != 1) continue;
            if (a[j] == 0) continue;
            if (i == j)
                res += (a[i] * (a[i - 1])) / 2;
            else
                res += a[i] * a[j];
        }
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    vector<int> arr = {1, 2, 1, 3};
    cout << countPairs(arr);
}
