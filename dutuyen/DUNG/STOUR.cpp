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
const int N = 1e5 + 69;
const int BASE = 256;
const int MOD = 1e9 + 7;
int add(int a, int b)
{
    return (a + b) % MOD;
}
int sub(int a, int b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
int mul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
int n, s, d, ans = 0;
struct Node
{
    vector<int> sortv;
    vector<long long> sum;
} tree[4 * N];
vector<int> a;
void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id].sortv.push_back(a[l]);
        tree[id].sum.push_back(0);
        tree[id].sum.push_back(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    merge(tree[id << 1].sortv.begin(), tree[id << 1].sortv.end(),
          tree[id << 1 | 1].sortv.begin(), tree[id << 1 | 1].sortv.end(),
          back_inserter(tree[id].sortv));
    int sz = tree[id].sortv.size();
    tree[id].sum.assign(sz + 1, 0);
    for (int i = 1; i <= sz; i++)
        tree[id].sum[i] = tree[id].sum[i - 1] + tree[id].sortv[i - 1];
}
int cnt(int id, int l, int r, int u, int v, int val)
{
    if (l > v || r < u)
        return 0;
    if (u <= l && r <= v)
    {
        auto it = lower_bound(tree[id].sortv.begin(), tree[id].sortv.end(), val);
        return tree[id].sortv.end() - it;
    }
    int mid = (l + r) >> 1;
    return cnt(id << 1, l, mid, u, v, val) + cnt(id << 1 | 1, mid + 1, r, u, v, val);
}
int sumlrk(int id, int l, int r, int u, int v, int val)
{
    if (l > v || r < u)
        return 0;
    if (u <= l && r <= v)
    {
        auto it = lower_bound(tree[id].sortv.begin(), tree[id].sortv.end(), val);
        int idx = it - tree[id].sortv.begin();
        return tree[id].sum.back() - tree[id].sum[idx];
    }
    int mid = (l + r) >> 1;
    return sumlrk(id << 1, l, mid, u, v, val) + sumlrk(id << 1 | 1, mid + 1, r, u, v, val);
}
int get(int l, int r, int remd)
{
    int len = r - l + 1;
    int rk = min(remd, len);
    if (rk <= 0)
        return 0;
    int lo = 0, hi = 1e9, ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if (cnt(1, 0, n - 1, l, r, mid) >= rk)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    int cntk = cnt(1, 0, n - 1, l, r, ans + 1);
    int sumk = sumlrk(1, 0, n - 1, l, r, ans + 1);
    int remk = rk - cntk;
    return sumk + remk * ans;
}
void solve()
{
    auto st = chrono::steady_clock::now();
    a.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    for (int l = s; l >= 0; l--)
    {
        if (chrono::duration<double>(chrono::steady_clock::now() - st).count() > 0.55)
        {
            cout << ans;
            return;
        }
        int movecost = (s - l);
        if (movecost > d)
            break;
        for (int r = l; r < n; r++)
        {
            if (chrono::duration<double>(chrono::steady_clock::now() - st).count() > 0.55)
            {
                cout << ans;
                return;
            }
            int movecost2 = (r - l);
            if (movecost + movecost2 > d)
                break;
            int remd = d - (movecost + movecost2);
            ans = max(ans, get(l, r, remd));
        }
    }
    for (int r = s; r < n; r++)
    {
        if (chrono::duration<double>(chrono::steady_clock::now() - st).count() > 0.55)
        {
            cout << ans;
            return;
        }
        int movecost = (r - s);
        if (movecost > d)
            break;
        for (int l = r; l >= 0; l--)
        {
            if (chrono::duration<double>(chrono::steady_clock::now() - st).count() > 0.55)
            {
                cout << ans;
                return;
            }
            int movecost2 = (r - l);
            if (movecost + movecost2 > d)
                break;
            int remd = d - (movecost + movecost2);
            ans = max(ans, get(l, r, remd));
        }
    }

    cout << ans << endl;
}
main()
{
    skibidi;
    file("STOUR");
    cin >> n >> s >> d;
    if (s == 0)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int cur = 0;
        a.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pq.push(a[i]);
            cur += a[i];
            while (!pq.empty() && i + pq.size() > d)
            {
                cur -= pq.top();
                pq.pop();
            }
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    else
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