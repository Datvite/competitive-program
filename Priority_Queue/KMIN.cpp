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
int n, m, k, a[N], b[N];
priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> q;
map<ii, int> mp;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    q.push({a[1] + b[1], {1, 1}});
    int cnt = 1;
    while (cnt <= k)
    {
        pair<int, ii> tmp = q.top();
        q.pop();
        if (mp[{tmp.se.fi, tmp.se.se}])
            continue;
        cout << tmp.fi << endl;
        int i = tmp.se.fi, j = tmp.se.se;
        mp[{i, j}] = 1;
        if (i == n && j == m)
            break;
        else if (i == n)
            q.push({a[i] + b[j + 1], {i, j + 1}});
        else if (j == m)
            q.push({a[i + 1] + b[j], {i + 1, j}});
        else
        {
            q.push({a[i + 1] + b[j], {i + 1, j}});
            q.push({a[i] + b[j + 1], {i, j + 1}});
        }
        cnt++;
    }
}
main()
{
    skibidi;
    file("KMIN");
    cin >> n >> m >> k;
    solve();
}
