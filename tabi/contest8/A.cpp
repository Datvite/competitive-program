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
int n, a[N];
bool snt[N];
void sieve()
{
    snt[0] = snt[1] = 0;
    for (int i = 2; i * i < N; i++)
        if (snt[i])
            for (int j = i * i; j < N; j += i)
                snt[j] = 0;
}
void solve()
{
    for (int i = 2 * n; i >= 2; i--)
    {
        if (!snt[i])
            continue;
        int l = max(1LL, i - n);
        int r = min(n, i - 1);
        for (int j = l; j <= r; j++)
        {
            int x = i - j;
            if (a[j] == 0 && a[x] == 0)
            {
                a[j] = x;
                a[x] = j;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == 0)
        {
            cout << "IMPOSSIBLE";
            return;
        }
    for (int i = 1; i <= n; i++)
        cout << i << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}
main()
{
    skibidi;
    file("");
    memset(snt, 1, sizeof(snt));
    cin >> n;
    sieve();
    solve();
}
