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
int n, a[N], maxa = 0;
unordered_map<int, int> mp;
int pw[N], h[N];
void build()
{
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * BASE % MOD;
    for (int i = 1; i <= n; i++)
        h[i] = (h[i - 1] * BASE + a[i]) % MOD;
}

int get(int l, int r)
{
    return (h[r] - h[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;
}
ii check(int mid)
{
    unordered_map<int, int> tmp;
    for (int i = 1; i <= n - mid + 1; i++)
    {
        tmp[get(i, i + mid - 1)]++;
    }
    for (int i = n; i >= mid; i--)
    {
        if (tmp[get(i - mid + 1, i)] >= maxa)
            return {1, i - mid + 1};
    }
    return {0, 0};
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        maxa = max(maxa, mp[a[i]]);
    }
    build();
    int l = 1, r = n, ans = 0, last;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        ii cur = check(mid);
        if (cur.fi)
        {
            ans = mid;
            last = cur.se;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << last << " " << last + ans - 1 << endl;
}
main()
{
    skibidi;
    file("BAI4");
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
