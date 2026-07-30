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
#define ii pair<long long, long long>
#define iii pair<long long, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const long long N = 1e6 + 69;
const long long BASE = 256;
const long long MOD = 1e9 + 7;
long long add(long long a, long long b)
{
    return (a + b) % MOD;
}

long long sub(long long a, long long b)
{
    return ((a - b) % MOD + MOD) % MOD;
}

long long mul(long long a, long long b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
long long n, ans = 0;
vector<long long> v1, v2;
ii a[N];
void backtrack1(long long id, long long M)
{
    if (M > 1e15)
        return;
    if (id > n / 2)
    {
        v1.push_back(M);
        return;
    }
    backtrack1(id + 1, M);
    long long s = 1;
    for (long long i = 1; i <= a[id].se; i++)
    {
        s *= a[id].fi;
        if (s > 1e15)
            return;
        backtrack1(id + 1, M * s);
    }
}
void backtrack2(long long id, long long M)
{
    if (M > 1e15)
        return;
    if (id > n)
    {
        v2.push_back(M);
        return;
    }
    long long s = 1;
    backtrack2(id + 1, M);
    for (long long i = 1; i <= a[id].se; i++)
    {
        s *= a[id].fi;
        if (s > 1e15)
            return;
        backtrack2(id + 1, M * s);
    }
}
bool check(long long mid, long long t)
{
    long long res = 0;
    for (auto x : v2)
    {
        long long tmp2 = mid / x;
        auto id2 = upper_bound(v1.begin(), v1.end(), tmp2);
        res += id2 - v1.begin();
    }
    return res < t;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
    for (long long i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    shuffle(a + 1, a + n + 1, rng);
    backtrack1(1, 1);
    backtrack2(n / 2 + 1, 1);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for (long long i = 1; i <= 3; i++)
    {
        long long t;
        cin >> t;
        long long l = 0, r = 1e15, ans = 0;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (check(mid, t))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans + 1 << endl;
    }
}

int main()
{
    skibidi;
    file("UST");
    cin >> n;
    solve();
    return 0;
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