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
vector<int> v;
bool snt[N];
void sieve()
{
    snt[0] = snt[1] = 0;
    for (int i = 2; i * i <= 1e6; i++)
    {
        if (snt[i])
        {
            for (int j = i * i; j <= 1e6; j += i)
                snt[j] = 0;
        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cout << *lower_bound(v.begin(), v.end(), a[i]) << " ";
    }
}
main()
{
    skibidi;
    file("SDB");
    cin >> n;
    memset(snt, 1, sizeof(snt));
    sieve();
    for (int i = 2; i <= 1e6; i++)
    {
        if (snt[i])
        {
            v.push_back(i * i);
        }
    }
    solve();
}
