#include <bits/stdc++.h>
#define maxn 10000
using namespace std;

vector<int> St(4 * maxn, 0);
vector<int> a(maxn, 0);
int n;

void update(int id, int l, int r, int i, int v)
{
    if (i < l || i > r)
        return;
    if (l == r)
    {
        St[id] == v;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);
    St[id] = max(St[id * 2], St[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        // Đoạn [u, v] không giao với đoạn [l, r], ta bỏ qua đoạn này
        return -INFINITY;
    }
    if (u <= l && r <= v)
    {
        // Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, ta trả lại
        // thông tin lưu ở nút id
        return St[id];
    }
    int mid = (l + r) / 2;
    // Gọi đệ quy với các con của nút id
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void build(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        St[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    St[id] = max(St[id * 2], St[id * 2 + 1]);
}
void input()
{
}
int main()
{
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    
}