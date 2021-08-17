#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200009;

using namespace std;

int n, m, a[N], pos[N], res = 0;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;


    pos[0] = n + 1;
    pos[n + 1] = -1;    
    for (int i = 1; i <= n; i++) {
        if (pos[a[i] - 1] < i) continue;
        res++;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
		int r = a[x], l = a[y];
		swap(a[x], a[y]);
		if (pos[r - 1] <= pos[r] && pos[r - 1] > y) res++;
		if (pos[r - 1] > pos[r] && pos[r - 1] <= y) res--;
		if (pos[r] <= pos[r + 1] && y > pos[r + 1]) res++;
		if (pos[r] > pos[r + 1] && y <= pos[r + 1]) res--;		
		
        pos[r] = y;

		if (pos[l - 1] <= pos[l] && pos[l - 1] > x) res++;
		if (pos[l - 1] > pos[l] && pos[l - 1] <= x) res--;
		if (pos[l] <= pos[l + 1] && x > pos[l + 1]) res++;
		if (pos[l] > pos[l + 1] && x <= pos[l + 1]) res--;	
		pos[l] = x;
		cout<< res << "\n";
    }
}
