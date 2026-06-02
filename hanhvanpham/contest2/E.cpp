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
int n;
iii a[N];
void solve()
{
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i].fi >> a[i].se.fi >> a[i].se.se;
            a[i].fi += 100;
            a[i].se.fi += 100;
        }
    int curx = 100, cury = 100, curt = 0;
    for (int i = 1; i <= n; i++)
    {
        int dx = abs(a[i].fi - curx);
        int dy = abs(a[i].se.fi - cury);
        int t = a[i].se.se - curt;
        if (dx + dy > t)
        {
            //cout << t << " ";
            cout << "NO" << endl;
            return;
        }
        curx = a[i].fi;
        cury = a[i].se.fi;
        curt = a[i].se.se;
    }
    cout << "YES" << endl;
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
