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
int n, a[N], lmin[N], lmax[N], rmin[N], rmax[N], ans = 0;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        if (st.empty())
            lmax[i] = 0;
        else
            lmax[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            lmin[i] = 0;
        else
            lmin[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[st.top()] < a[i])
            st.pop();
        if (st.empty())
            rmax[i] = n + 1;
        else
            rmax[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[st.top()] > a[i])
            st.pop();
        if (st.empty())
            rmin[i] = n + 1;
        else
            rmin[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int minn = (i - lmin[i]) * (rmin[i] - i);
        int maxn = (i - lmax[i]) * (rmax[i] - i);
        ans += (maxn - minn) * a[i];
    }
    cout << ans;
}
main()
{
    skibidi;
    file("DAYSO");
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
