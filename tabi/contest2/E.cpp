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
int n, k, a[N];
void solve(int l, int r)
{
    if (k == 1 || l + 1 >= r)
        return;
    int mid = (l + r) / 2;
    k -= 2;
    swap(a[mid - 1], a[mid]);
    solve(l, mid);
    solve(mid, r);
}
void solve()
{
    cin >> n >> k;
    if (k % 2 == 0 || k > 2 * n - 1)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    solve(0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
main()
{
    skibidi;
    file("");
    solve();
}
