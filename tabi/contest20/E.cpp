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
int n, a[N], last[N], last2[N], res = 0;
vector<int> tree[4 * N];
vector<int> merge_vec(const vector<int> &a, const vector<int> &b)
{
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
    }
    while (i < a.size())
        res.push_back(a[i++]);
    while (j < b.size())
        res.push_back(b[j++]);
    return res;
}
void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id].push_back(last[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = merge_vec(tree[id * 2], tree[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v, int L)
{
    if (r < u || v < l)
        return 0;
    if (u <= l && r <= v)
        return lower_bound(tree[id].begin(), tree[id].end(), L) - tree[id].begin();
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v, L) + get(id * 2 + 1, mid + 1, r, u, v, L);
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        last[i] = last2[a[i]];
        last2[a[i]] = i;
    }
    build(1, 1, n);
    for (int k = 1; k <= n; k++)
    {
        int l = 1;
        res = 0;
        while (l <= n)
        {
            int lo = l, hi = n, ans = l;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if (get(1, 1, n, l, mid, l) <= k)
                {
                    lo = mid + 1;
                    ans = mid;
                }
                else
                    hi = mid - 1;
            }
            res++;
            l = ans + 1;
        }
        cout << res << " ";
    }
}
main()
{
    skibidi;
    file("");
    cin >> n;
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
