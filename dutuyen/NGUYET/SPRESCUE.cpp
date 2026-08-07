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
int n, a[N], b[N], c[N], ansa = 0, ansb = 0, ansc = 0, res = 0, maxna = -1e18, maxnb = -1e18, maxnc = -1e18, minna = 1e18, minnb = 1e18, minnc = 1e18;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        maxna = max(maxna, a[i]);
        maxnb = max(maxnb, b[i]);
        maxnc = max(maxnc, c[i]);
        minna = min(minna, a[i]);
        minnb = min(minnb, b[i]);
        minnc = min(minnc, c[i]);
    }
    ansa = (maxna + minna) / 2;
    ansb = (maxnb + minnb) / 2;
    ansc = (maxnc + minnc) / 2;
    for (int i = 1; i <= n; i++)
    {
        int cur1 = abs(a[i] - ansa);
        int cur2 = abs(b[i] - ansb);
        int cur3 = abs(c[i] - ansc);
        if ((cur1 != cur2 && cur2 == cur3 && cur1 == cur3) || (cur1 == cur2 && cur2 == cur3 && cur1 != cur3) || (cur1 != cur2 && cur2 == cur3 && cur1 == cur3))
        {
            res = max(res, max(cur1, max(cur2, cur3)) + 1);
        }
        else
            res = max(res, max(cur1, max(cur2, cur3)));
    }
    cout << res << endl;
}
main()
{
    skibidi;
    file("sprescue");
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
