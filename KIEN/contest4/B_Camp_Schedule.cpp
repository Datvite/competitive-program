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
const int BASE = 311;
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
int n, a[N], cnt[2], len = 0;
string str, str2, news;
string s;
int pw[N], h[N], revh[N];
void build_hash(string s)
{
    int n = s.size();
    s = ' ' + s;

    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * BASE % MOD;

    for (int i = 1; i <= n; i++)
        h[i] = (h[i - 1] * BASE + s[i]) % MOD;
}

int get_hash(int l, int r)
{
    return (h[r] - h[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;
}
void solve()
{
    string s, t;
    cin >> s >> t;
    for (char c : s)
        cnt[c - '0']++;
    int n = s.size();
    int m = t.size();
    build_hash(t);
    int len = 0;
    for (int i = 1; i < m; i++)
        if (get_hash(1, i) == get_hash(m - i + 1, m))
            len = i;
    string news = "";
    int id = 0;
    for (int i = 0; i < n; i++)
    {
        int x = t[id] - '0';
        if (cnt[x] > 0)
        {
            news += t[id];
            cnt[x]--;
            id++;
            if (id == m)
                id = len;
        }
        else
            break;
    }
    while (cnt[0]--)
        news += '0';
    while (cnt[1]--)
        news += '1';
    cout << news << endl;
}
main()
{
    skibidi;
    file("");
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