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
string str;
void solve()
{
    int cnt = 0;
    for (int i = 0; i < str.size() - 1; i++)
    {
        cnt++;
        if (str[i] != str[i + 1])
        {
            if (cnt > 1)
                cout << cnt;
            cout << str[i];
            cnt = 0;
        }
    }
    cout << endl;
}
main()
{
    skibidi;
    file("THUGON");
    while (cin >> str)
    {
        str = str + '#';
        solve();
    }
}
