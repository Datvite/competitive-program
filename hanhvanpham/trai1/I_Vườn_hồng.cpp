#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout); \
    }
#define int long long
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;

const int N = 1e6 + 5;
const int INF = 1e18;

int n, q;
int a[N];
int death_time[N]; // -1 = never died, otherwise attack index
int ans[N];

struct SegTree
{
    int mn[4 * N], lazy[4 * N];

    void build(int node, int l, int r)
    {
        if (l == r)
        {
            mn[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);
        mn[node] = min(mn[node << 1], mn[node << 1 | 1]);
    }

    void push(int node)
    {
        if (lazy[node] != 0)
        {
            int lz = lazy[node];
            mn[node << 1] += lz;
            lazy[node << 1] += lz;
            mn[node << 1 | 1] += lz;
            lazy[node << 1 | 1] += lz;
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int u, int v, int val)
    {
        if (u <= l && r <= v)
        {
            mn[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = (l + r) >> 1;
        if (u <= mid)
            update(node << 1, l, mid, u, v, val);
        if (v > mid)
            update(node << 1 | 1, mid + 1, r, u, v, val);
        mn[node] = min(mn[node << 1], mn[node << 1 | 1]);
    }

    // Kill all positions in [u, v] whose health just dropped to <= 0
    void kill(int node, int l, int r, int u, int v, int cur_attack)
    {
        if (mn[node] > 0)
            return;
        if (l == r)
        {
            death_time[l] = cur_attack;
            mn[node] = INF;
            return;
        }
        push(node);
        int mid = (l + r) >> 1;
        if (u <= mid)
            kill(node << 1, l, mid, u, v, cur_attack);
        if (v > mid)
            kill(node << 1 | 1, mid + 1, r, u, v, cur_attack);
        mn[node] = min(mn[node << 1], mn[node << 1 | 1]);
    }
} seg;

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        death_time[i] = -1;
    }

    seg.build(1, 1, n);

    // Handle towers that start already destroyed (health <= 0)
    seg.kill(1, 1, n, 1, n, 0);

    for (int attack_idx = 1; attack_idx <= q; attack_idx++)
    {
        int l, r, s;
        cin >> l >> r >> s;
        seg.update(1, 1, n, l, r, -s);
        seg.kill(1, 1, n, l, r, attack_idx);
    }

    // Compute answer for each garden
    for (int i = 1; i <= n; i++)
    {
        int mx = -1;
        bool all_dead = true;
        for (int j = i; j <= n; j += i)
        {
            if (death_time[j] == -1)
            {
                all_dead = false;
                break;
            }
            mx = max(mx, death_time[j]);
        }
        ans[i] = (all_dead ? mx : -1);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

signed main()
{
    skibidi;
    file("");
    solve();
}
/*  I am the bone of my sword
    Steel is my body and fire is my blood
    I have created over a thousand blades
    Unknown to Death,
    Nor known to Life.
    Have withstood pain to create many weapons
    Yet, those hands will never hold anything
    So as I pray, unlimited blade works.
*/