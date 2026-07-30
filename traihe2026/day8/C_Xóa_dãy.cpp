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
const int BASE = 366;
const int BASE2 = 673669;
const int MOD = 1e9 + 7;
const int MOD2 = 2e9 + 11;
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
int n, k, q, a[N], hash1[N], hash2[N];
map<int, ii> val;
mt19937_64 rng(13373713);
ii geth(int x)
{
    int cur = k - x;
    int key = x * 1e9 + cur;
    if (val.find(key) != val.end())
    {
        return val[key];
    }
    int r1 = rng() % MOD;
    int r2 = rng() % MOD2;
    val[key] = {r1, r2};
    return val[key];
}
int st[N];
int id[N];
int top = 0;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ii tmp = geth(a[i]);
        int h1 = tmp.fi;
        int h2 = tmp.se;
        if (top > 0 && st[top] + a[i] == k)
        {
            top--;
            hash1[i] = hash1[id[top]];
            hash2[i] = hash2[id[top]];
        }
        else
        {
            top++;
            st[top] = a[i];
            id[top] = i;
            hash1[i] = (hash1[id[top - 1]] * BASE + h1) % MOD;
            hash2[i] = (hash2[id[top - 1]] * BASE2 + h2) % MOD2;
        }
    }
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (hash1[r] == hash1[l - 1] && hash2[r] == hash2[l - 1])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
main()
{
    skibidi;
    file("");
    cin >> n >> k;
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
