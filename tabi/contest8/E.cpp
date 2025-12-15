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
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 2e5 + 69;
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
int a[N];
vector<int> cnt[N];
vector<int> ans[N];
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

bool cmp(query a, query b)
{
    if (a.l / S == b.l / S)
        return a.r < b.r;
    return a.l < b.l;
}
void reset()
{
    for (int i = 1; i <= q; i++)
        ans[i].clear();
    for (int i = 1; i <= n; i++)
        cnt[i].clear();
    L = 1;
    R = 0;
}
void solve()
{
    cin >> n >> q;
    reset();
    S = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // nén số
    vector<int> tmp(a + 1, a + n + 1);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin() + 1;
    for (int i = 1; i <= n; i++)
        cnt[a[i]].push_back(i);
    for (int i = 1; i <= q; i++)
    {
        cin >> qu[i].l >> qu[i].r;
        qu[i].id = i;
    }
    sort(qu + 1, qu + 1 + q, cmp);
    for (int i = 1; i <= q; i++)
    {
        int len = (qu[i].r - qu[i].l + 1) / 3;
        unordered_map<int, int> used;
        for (int j = 1; j <= 60; j++)
        {
            int pos = rand(qu[i].l, qu[i].r);
            int cnts = upper_bound(cnt[a[pos]].begin(), cnt[a[pos]].end(), qu[i].r) - lower_bound(cnt[a[pos]].begin(), cnt[a[pos]].end(), qu[i].l);
            if (cnts > len)
                used[a[pos]]++;
        }
        for (auto x : used)
        {
            int val = x.fi;
            int cnts = upper_bound(cnt[val].begin(), cnt[val].end(), qu[i].r) - lower_bound(cnt[val].begin(), cnt[val].end(), qu[i].l);
            if (cnts > len)
                ans[qu[i].id].push_back(tmp[val - 1]);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        sort(ans[i].begin(), ans[i].end());
        if (ans[i].size() == 0)
            cout << -1;
        else
            for (auto z : ans[i])
                cout << z << " ";
        cout << endl;
    }
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
        solve();
}
