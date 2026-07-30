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
const int N = 1e3 + 69;
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
int n, m, ans = 0;
string white[N], black[N];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> white[i];
    for (int i = 1; i <= n; i++)
        cin >> black[i];
    for (int i = 0; i < m; i++)
    {
        int wh = 0;
        for (int j = 1; j <= n; j++)
        {
            if (white[j][i] == 'A')
                wh = wh | (1 << 1);
            else if (white[j][i] == 'C')
                wh = wh | (1 << 2);
            else if (white[j][i] == 'G')
                wh = wh | (1 << 3);
            else if (white[j][i] == 'T')
                wh = wh | (1 << 4);
        }
        int bl = 0;
        for (int j = 1; j <= n; j++)
        {
            if (black[j][i] == 'A')
                bl = bl | (1 << 1);
            else if (black[j][i] == 'C')
                bl = bl | (1 << 2);
            else if (black[j][i] == 'G')
                bl = bl | (1 << 3);
            else if (black[j][i] == 'T')
                bl = bl | (1 << 4);
        }
        if (wh & bl)
            ans++;
    }
    cout << m - ans << endl;
}
main()
{
    skibidi;
    file("CLASSIFY");
    cin >> n >> m;
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
