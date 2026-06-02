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
int n, a[N], in[N], nxt[N];
bool check[N];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        nxt[x] = y;
        in[y]++;
        if (x == 0)
            a[2] = y;
        check[x] = check[y] = 1;
    }
    for (int i = 1; i < N; i++)
    {
        if (in[i] == 0 && check[i])
        {
            a[1] = i;
            break;
        }
    }
    for (int i = 3; i <= n; i += 2)
        a[i] = nxt[a[i - 2]];
    for (int i = 4; i <= n; i += 2)
        a[i] = nxt[a[i - 2]];
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}
main()
{
    skibidi;
    file("");
    cin >> n;
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
