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
const int N = 1e6 + 69;
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
int n, m, q, a[N], x, y, maxn = 0, st = 0, c[N];
deque<int> dq;
vector<ii> ans;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dq.push_back(a[i]);
        maxn = max(maxn, a[i]);
    }
    while (1)
    {
        x = dq.front();
        dq.pop_front();
        y = dq.front();
        dq.pop_front();
        dq.push_front(max(x, y));
        dq.push_back(min(x, y));
        st++;
        ans.push_back({x, y});
        if (max(x, y) == maxn)
            break;
    }
    dq.pop_front();
    for (int i = 1; i < n; i++)
    {
        c[i] = dq.front();
        dq.pop_front();
    }
    c[0] = c[n - 1];
    int len = n - 1;
    while (q--)
    {
        int k;
        cin >> k;
        if (k <= st)
            cout << ans[k - 1].fi << " " << ans[k - 1].se << endl;
        else
        {
            k -= st;
            k %= len;
            cout << maxn << " " << c[k] << endl;
        }
    }
}
main()
{
    skibidi;
    file("");
    cin >> n >> q;
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
