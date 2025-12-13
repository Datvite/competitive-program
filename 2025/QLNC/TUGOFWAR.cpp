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
int n, a[N], ans = 1e18, s = 0;
bool mark[N], vis[N];
vector<int> v, res;
void Try(int id, int sum1)
{
    if (ans == 0 || mark[s - 2 * sum1])
        return;
    if (id > n)
    {
        if (abs(s - 2 * sum1) < ans)
        {
            ans = abs(s - 2 * sum1);
            res = v;
        }
        mark[s - 2 * sum1] = 1;
        return;
    }
    v.push_back(id);
    Try(id + 1, sum1 + a[id]);
    v.pop_back();
    Try(id + 1, sum1);
}
void solve()
{
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
    Try(1, 0);
    cout << res.size() << " " << n - res.size() << endl;
    for (auto x : res)
        {
            cout << x << " ";
            vis[x] = 1;
        }
    cout << endl;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            cout << i << " ";
}
main()
{
    skibidi;
    file("TUGOFWAR");
    cin >> n;
    solve();
}
