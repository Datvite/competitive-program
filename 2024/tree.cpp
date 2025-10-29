#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
struct Node {
    long long sum, pre, suf, ma;
};
Node T[4 * N];
Node combine(Node a, Node b) {
    Node ans;
    ans.sum = a.sum + b.sum;
    ans.pre = max(a.pre, a.sum + b.pre);
    ans.suf = max(b.suf, b.sum + a.suf);
    ans.ma = max({a.ma, b.ma, a.suf + b.pre});
    return ans;
}
void build(int l, int r, int k) {
    if (l == r) {
        T[k] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, k << 1);
    build(m + 1, r, k << 1 | 1);
    T[k] = combine(T[k << 1], T[k << 1 | 1]);
}
long long b = -1e18;
Node sum(int l, int r, int k, int x, int y) {
    if (x > r || y < l) return {0ll,-15000*50000,-15000*50000,-15000*50000};
    if (x <= l && r <= y) return T[k];
    int m = (l + r) >> 1;
    return combine(sum(l, m, k << 1, x, y), sum(m + 1, r, k << 1 | 1, x, y));
}
int main() {
    freopen("GSS.INP", "r", stdin);
    freopen("GSS.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, n - 1, 1);
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        auto ans = sum(0, n - 1, 1, l - 1, r - 1);
        cout << ans.ma << "\n";
    }
}
