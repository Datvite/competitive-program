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
const int MOD = 2000000011LL;

int add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}
int sub(int a, int b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
int mul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
int n, m, a[N], b[N], Hash[N], power[N], H, ans = 0;
int getHash(int l, int r)
{
    return sub(Hash[r], mul(Hash[l - 1], power[r - l + 1]));
}
void solve()
{
    if (n > m)
    {
        cout << 0;
        return;
    }
    power[0] = 1;
    for (int i = 1; i <= max(n, m); i++)
        power[i] = mul(power[i - 1], BASE);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i < n; i++)
        a[i] = abs(a[i + 1] - a[i]);
    for (int i = 1; i < m; i++)
        b[i] = abs(b[i + 1] - b[i]);
    H = 0;
    for (int i = 1; i < n; i++)
        H = add(mul(H, BASE), a[i]);
    Hash[0] = 0;
    for (int i = 1; i < m; i++)
        Hash[i] = add(mul(Hash[i - 1], BASE), b[i]);
    for (int i = n - 1; i < m; i++)
    {
        int l = i - n + 2;
        //cout << H << " " << l << " " << i << " " << getHash(l, i) << endl;
        if (H == getHash(l, i))
            ans++;
    }
    cout << ans;
}

main()
{
    skibidi;
    file("PUZZLE");
    cin >> n >> m;
    solve();
}
