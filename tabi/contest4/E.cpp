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
const int N = 5e3 + 69;
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
int n, k, x, a[N], dp1[N], dp2[N];
deque<int> dq;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (i <= k)
            dp1[i] = a[i];
        else
            dp1[i] = -1e18;
    for (int j = 2; j <= x; j++)
    {
        dq.clear();
        for (int i = 1; i <= n; i++)
            dp2[i] = -1e18;
        for (int i = 1; i <= n; i++)
        {
            while (!dq.empty() && dq.front() < i - k)
                dq.pop_front();
            int id = i - 1;
            if (id >= 1)
            {
                while (!dq.empty() && dp1[dq.back()] <= dp1[id])
                    dq.pop_back();
                dq.push_back(id);
            }
            if (!dq.empty())
                dp2[i] = dp1[dq.front()] + a[i];
        }
        for (int i = 1; i <= n; i++)
            dp1[i] = dp2[i];
    }
    int res = -1;
    for (int i = n - k + 1; i <= n; i++)
        res = max(res, dp1[i]);
    cout << res << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> k >> x;
    solve();
}
