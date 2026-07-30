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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_hash(int l, int r)
{
    return uniform_int_distribution<long long>(l, r)(rng);
}
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
int n, k, a[N], cnt[N];
int cost = 0;
int cur[N], pre[N];
map<long long, long long> mp;
vector<int> values;
int prexor[N];
int gethash(int x)
{
    if (mp.count(x))
        return mp[x];
    return mp[x] = rand_hash(1, 1e18);
}
inline void add(int idx)
{
    cost += cnt[prexor[idx]];
    cnt[prexor[idx]]++;
}

inline void remove(int idx)
{
    cnt[prexor[idx]]--;
    cost -= cnt[prexor[idx]];
}
int L = 1;
int R = 0;
void mo(int l, int r)
{
    l--;
    while (L > l)
        add(--L);

    while (R < r)
        add(++R);

    while (L < l)
        remove(L++);

    while (R > r)
        remove(R--);
}
void compute(int l, int r, int optl, int optr)
{
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    long long best_val = 1e18;
    int best_opt = -1;

    int limit = min(mid - 1, optr);
    for (int m = optl; m <= limit; ++m)
    {
        mo(m + 1, mid);
        long long val = pre[m] + cost;
        if (val < best_val)
        {
            best_val = val;
            best_opt = m;
        }
    }

    cur[mid] = best_val;

    compute(l, mid - 1, optl, best_opt);
    compute(mid + 1, r, best_opt, optr);
}
void solve()
{
    values.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prexor[i] = prexor[i - 1] ^ gethash(a[i]);
        values.push_back(prexor[i]);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 0; i <= n; i++)
        prexor[i] = lower_bound(values.begin(), values.end(), prexor[i]) - values.begin();
    for (int i = 1; i <= n; i++)
        pre[i] = 1e18;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
            cur[j] = 1e18;
        L = 1;
        R = 0;
        cost = 0;
        memset(cnt, 0, sizeof(cnt));
        compute(i, n, i - 1, n - 1);
        for (int j = 0; j <= n; j++)
            pre[j] = cur[j];
    }
    cout << pre[n] << endl;
}
main()
{
    skibidi;
    file("NULLCYCLE");
    cin >> n >> k;
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
