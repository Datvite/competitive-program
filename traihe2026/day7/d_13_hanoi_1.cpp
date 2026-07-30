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
int n, a[N];
vector<ii> v;
void backtrack(int n, int from, int to, int tmp)
{
    if (n == 1)
    {
        v.push_back({from, to});
        return;
    }
    backtrack(n - 1, from, tmp, to);
    v.push_back({from, to});
    backtrack(n - 1, tmp, to, from);
}
void solve()
{
    backtrack(n, 1, 3, 2);
    cout << v.size() << endl;
    for (auto &p : v)
    {
        char ch, ch1;
        if (char(p.se + 'A' - 1) == 'C')
            ch = 'D';
        else
            ch = char(p.se + 'A' - 1);
        if (char(p.fi + 'A' - 1) == 'C')
            ch1 = 'D';
        else
            ch1 = char(p.fi + 'A' - 1);
        cout << ch1 << ch << endl;
    }
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
