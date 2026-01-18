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
int n, q, a[N], exist = 0, nonexist = 0;
unordered_map<int, int> mark;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (mark[a[i]] == 0)
            mark[a[i]] = i;
    }
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (mark[x] != 0)
        {
            cout << mark[x] << endl;
            exist++;
        }
        else
        {
            cout << -1 << endl;
            nonexist++;
        }
    }
    if (exist > nonexist)
        cout << 1;
    else if (exist < nonexist)
        cout << -1;
    else
        cout << 0;
}
main()
{
    skibidi;
    file("Game");
    cin >> n;
    solve();
}
