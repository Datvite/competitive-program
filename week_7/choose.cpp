#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout);  \
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
int n, m, a[N], b[N];
map<ii, int> mp;
priority_queue<iii, vector<iii>, greater<iii>> v;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    v.push({a[1] + b[1], {1, 1}});
    mp[{1, 1}] = 1;
    while (m--)
    {
        iii top = v.top();
        v.pop();
        cout << top.fi << " ";
        int i = top.se.fi;
        int j = top.se.se;
        if (i + 1 <= n && !mp[{i + 1, j}])
        {
            v.push({a[i + 1] + b[j], {i + 1, j}});
            mp[{i + 1, j}] = 1;
        }
        if (j + 1 <= n && !mp[{i, j + 1}])
        {
            v.push({a[i] + b[j + 1], {i, j + 1}});
            mp[{i, j + 1}] = 1;
        }
    }
}
main()
{
    skibidi;
    file("");
    cin >> n >> m;
    solve();
}
