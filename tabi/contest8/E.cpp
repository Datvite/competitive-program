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
const int N = 1e6 + 69;
const int BASE = 256;
const int MOD = 2e9 + 11;
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
int n, t, q, S;
int a[N], cnt[N], ans[N];
int L = 1, R = 0;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r)
{
    return uniform_int_distribution<int>(l, r)(rng);
}
struct query
{
    int l, r, id;
} qu[N];

void MO(int i)
{   
    while (L < qu[i].l)
    {
        cnt[a[L]]--;
        L++;
    }
    while (L > qu[i].l)
    {
        L--;
        cnt[a[L]]++;
    }
    while (R < qu[i].r)
    {
        R++;
        cnt[a[R]]++;
    }
    while (R > qu[i].r)
    {
        cnt[a[R]]--;
        R--;
    }
}

bool cmp(query a, query b)
{
    if (a.l / S == b.l / S)
        return a.r < b.r;
    return a.l < b.l;
}
void reset()
{
    for (int i = 1; i <= n; i++)
        cnt[i] = 0;
    L = 1;
    R = 0;
}
void solve()
{
    reset();
    cin >> n >> q;
    S = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
    {
        cin >> qu[i].l >> qu[i].r;
        qu[i].id = i;
    }
    sort(qu + 1, qu + 1 + q, cmp);
    for (int i = 1; i <= q; i++)
    {
        MO(i);
        int res = 1e18;
        for (int j = 1; j <= 100; j++)
        {
            int id = rand(qu[i].l, qu[i].r);
            if (cnt[a[id]] > (qu[i].r - qu[i].l + 1) / 3)
                res = min(res, a[id]);
        }
        ans[qu[i].id] = res;
    }
    for (int i = 1; i <= q; i++)
        if (ans[i] == 1e18)
            cout << -1 << " ";
        else
            cout << ans[i] << endl;
    cout << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
        solve();
}
