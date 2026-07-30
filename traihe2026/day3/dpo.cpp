#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
int n, k, a[N], phi[N], cnt[N];
long long cost = 0;
int divs_st[N + 7], divs_en[N + 7];
int divs_list[1200005];
long long cur[N], pre[N];
void sieve()
{
    for (int i = 1; i < N; i++)
        phi[i] = i;
    for (int i = 2; i < N; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    static int cnt_divs[N + 7];
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            cnt_divs[j]++;
        }
    }

    int cur = 0;
    for (int i = 1; i <= N; i++)
    {
        divs_st[i] = cur;
        cur += cnt_divs[i];
        divs_en[i] = divs_st[i];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divs_list[divs_en[j]++] = i;
        }
    }
}
inline void add(int idx)
{
    int val = a[idx];
    for (int i = divs_st[val]; i < divs_en[val]; ++i)
    {
        int x = divs_list[i];
        cost += 1LL * phi[x] * cnt[x];
        cnt[x]++;
    }
}

inline void remove(int idx)
{
    int val = a[idx];
    for (int i = divs_st[val]; i < divs_en[val]; ++i)
    {
        int x = divs_list[i];
        cnt[x]--;
        cost -= 1LL * phi[x] * cnt[x];
    }
}
int L = 1;
int R = 0;
void mo(int l, int r)
{

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
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        pre[i] = 1e18;

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
            cur[j] = 1e18;
        compute(i, n, i - 1, n - 1);
        for (int j = 1; j <= n; j++)
            pre[j] = cur[j];
    }
    cout << pre[n] << endl;
}
main()
{
    skibidi;
    file("DPO");
    cin >> n >> k;
    sieve();
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
