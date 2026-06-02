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
int t, s, k, m, a[N];
int nxtnum(int x, int md)
{
    string st = to_string(x);
    sort(st.rbegin(), st.rend());
    string s2;
    for (auto c : st)
        s2 = s2 + c + c;
    return stoll(s2) % md;
}
void solve()
{
    cin >> s >> k >> m;
    unordered_map<int, int> mp;
    vector<int> v;
    int cur = s, cnt = 0;
    while (mp.find(cur) == mp.end())
    {
        mp[cur] = cnt;
        v.push_back(cur);
        cur = nxtnum(cur, m);
        cnt++;
    }
    int st = mp[cur];
    int len = cnt - st;
    if (k < cnt)
    {
        cout << v[k] << " ";
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
