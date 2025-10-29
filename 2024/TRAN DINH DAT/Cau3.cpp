#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, a[N], l, r;
vector<pair<int, int>> p[N];
int tree[4 * N];
void up(int id, int l, int r, int pos, int k)
{
    if (l == r)
    {
        tree[id] = k;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
        up(id * 2, l, m, pos, k);
    else
        up(id * 2 + 1, m + 1, r, pos, k);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
int get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u)
        return 0;
    if (u <= l && r <= v)
        return tree[id];
    int m = (l + r) >> 1;
    return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
}
int ans[N];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r;
        p[r].push_back({l, i});
    }
    unordered_map<int, int> last;
    for (int i = 1; i <= n; i++)
    {
        if (last[a[i]] != 0)
        {
            up(1, 1, n, last[a[i]], 0);
        }
        last[a[i]] = i;
        up(1, 1, n, last[a[i]], 1);
        for (auto x : p[i])
        {
            ans[x.second] = get(1, 1, n, x.first, i);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << '\n';
    }
}