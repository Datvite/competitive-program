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
int n, ans = 0;
string a[N], b[N];
vector<ii> res;
vector<ii> vec;
bool check[N];
void backtrack(int id, int sum)
{
    if (id > n)
    {
        if (sum > ans)
        {
            ans = sum;
            //res = vec;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (check[i])
            continue;
        int cur = 0;
        for (int j = 0; j < min(a[id].length(), b[i].length()); j++)
        {
            if (a[id][j] == b[i][j])
                cur++;
            else
                break;
        }
        //vec.push_back({id, i});
        check[i] = 1;
        backtrack(id + 1, sum + cur);
        // vec.pop_back();
        check[i] = 0;
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    backtrack(1, 0);
    cout << ans << endl;
    /*for (auto [x, y] : res)
        cout << x << " " << y << endl;*/
}
main()
{
    skibidi;
    file("FILM");
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
