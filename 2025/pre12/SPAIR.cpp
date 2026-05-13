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
int S, n, a[N];
vector<ii> ans;
void solve(int x)
{
    int cur = S / x - x + 1;
    if (cur % 2 == 0)
    {
        int y = cur / 2;
        if (y > 0)
            ans.push_back({y, y + x - 1});
    }
}
main()
{
    skibidi;
    file("SPAIR");
    cin >> S;
    S = 2 * S;
    for (int  i = 1; i * i <= S; i++)
    {
        if (S % i == 0)
        {
            solve(i);
            if (i != S / i)
                solve(S / i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto [l, r] : ans)
        cout << l << " " << r << endl;

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
