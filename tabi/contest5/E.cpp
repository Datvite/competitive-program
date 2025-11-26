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
const int MOD = 2e9 + 11;
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
int n, a[N], ans = 0, cnt = 0;
stack<int> st;
string str;
void solve()
{
    st.push(0);
    for (int i = 1; i <= n; i++)
    {
        if (str[i] == '(')
            st.push(i);
        else
        {
                st.pop();
            if (st.empty())
                st.push(i);
            else
            {
                int cur = i - st.top();
                if (cur > ans)
                {
                    ans = cur;
                    cnt = 1;
                }
                else if (cur == ans)
                    cnt++;
            }
        }
    }
    if (ans == 0)
        cout << "0 1";
    else
        cout << ans << " " << cnt;
}
main()
{
    skibidi;
    file("");
    cin >> str;
    n = str.size();
    str = " " + str;
    solve();
}
