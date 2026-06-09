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
int t, s, l, r, m, sum[N];
int nxtnum(int x, int md)
{
    string st = to_string(x);
    sort(st.rbegin(), st.rend());
    string s2;
    for (auto c : st)
        s2 = s2 + c + c;
    return stoll(s2) % md;
}
int getsum(int id, int cnt, int st, int len)
{
    if (id < 0)
        return 0;
    if (id < cnt)
        return sum[id];
    int bef = (st ? sum[st - 1] : 0);
    int cyc = sum[cnt - 1] - bef;
    id -= st;
    int res = bef;
    res += (id / len) * cyc;
    int rem = id % len;
    res += sum[st + rem] - bef;
    return res;
}
void solve()
{
    cin >> s >> m >> l >> r;
    unordered_map<int, int> mp;
    vector<int> v;
    int cur = s, cnt = 0;
    while (mp.find(cur) == mp.end())
    {
        mp[cur] = cnt;
        v.push_back(cur);
        if (cnt == 0)
            sum[cnt] = cur;
        else
            sum[cnt] = sum[cnt - 1] + cur;
        cur = nxtnum(cur, m);
        cnt++;
    }
    int st = mp[cur];
    int len = cnt - st;
    cout << getsum(r, cnt, st, len) - getsum(l - 1, cnt, st, len) << endl;
}
signed main()
{
    skibidi;
    file("sumnumber");
    cin >> t;
    while (t--)
        solve();
}