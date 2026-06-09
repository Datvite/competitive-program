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
const int MOD = 2207;
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
long long t, s, k, m, a[N];
int mp[MOD * MOD + 5];
int vis[MOD * MOD + 5];
int timer = 0;
long long nxtnum(long long x, long long i, long long a, long long b, long long c)
{
    long long cur = i % MOD;
    return (a * x % MOD * x % MOD + b * x % MOD * cur % MOD + c * cur % MOD * cur % MOD) % MOD;
}
void solve()
{
    long long a, b, c;
    cin >> s >> a >> b >> c >> k;
    s %= MOD;
    if (s < 0)
        s += MOD;
    a %= MOD;
    if (a < 0)
        a += MOD;
    b %= MOD;
    if (b < 0)
        b += MOD;
    c %= MOD;
    if (c < 0)
        c += MOD;
    vector<int> v;
    v.reserve(5000000);
    int cur = s;
    int cnt = 0;
    timer++;
    while (1)
    {
        int state = cur * MOD + (cnt % MOD);
        if (vis[state] == timer)
            break;
        vis[state] = timer;
        mp[state] = cnt;
        v.push_back(cur);
        cur = nxtnum(cur, cnt + 1, a, b, c);
        cnt++;
    }
    int state = cur * MOD + (cnt % MOD);
    int st = mp[state];
    int len = cnt - st;
    if (k < cnt)
    {
        cout << v[k] << endl;
    }
    else
    {
        k -= st;
        k %= len;
        cout << v[st + k] << " ";
    }
}
main()
{
    skibidi;
    file("findnumber");
    cin >> t;
    while (t--)
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
