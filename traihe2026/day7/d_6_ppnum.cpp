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
const int MOD = 1e18 + 7;
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
string l, r, num;
int dp[20][2][2][20][3]; // id, start, tight, R, check
bool prime[20];
int f(int id, int start, int tight, int R, int check)
{
    if (id > R)
    {
        if (check == 1 && tight)
            return 0;
        return 1;
    }
    if (dp[id][start][tight][R][check] != -1)
        return dp[id][start][tight][R][check];
    int limit, res = 0;
    if (tight)
        limit = num[id] - '0';
    else
        limit = 9;
    for (int num1 = 0; num1 <= limit; num1++)
    {
        bool nstart = start | (num1 != 0);
        bool ntight = tight && (num1 == limit);
        if (!nstart)
        {
            res = add(res, f(id + 1, nstart, ntight, R, check));
        }
        else if (id == R)
        {
            if (prime[num1 * 2])
                res = add(res, f(id + 1, nstart, ntight, R, check));
        }
        else
        {
            for (int num2 = 0; num2 <= 9; num2++)
            {
                if (prime[num1 + num2])
                    {
                        int ncheck = check;
                        if (num2 > (num[R] - '0'))
                            ncheck = 1;
                        else if (num2 < (num[R] - '0'))
                            ncheck = 2;
                        res = add(res, f(id + 1, nstart, ntight, R - 1, ncheck));
                    }
            }
        }
    }
    return dp[id][start][tight][R][check] = res;
}
int solve(string n)
{
    memset(dp, -1, sizeof(dp));
    num = n;
    return f(0, 0, 1, n.length() - 1, 0);
}
bool istrue(string n)
{
    int r = n.size() - 1;
    for (int i = 0; i < n.length() / 2; i++)
    {
        if (!prime[(n[i] - '0') + (n[r - i] - '0')])
            return 0;
    }
    return 1;
}
void sieve()
{
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int i = 2; i < 20; i++)
        if (prime[i])
            for (int j = i * i; j < 20; j += i)
                prime[j] = 0;
}
main()
{
    file("");
    sieve();
    cin >> l >> r;
    cout << add(sub(solve(r), solve(l)), istrue(l)) << endl;
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
