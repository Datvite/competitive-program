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
const int maxn = 1e4;
int n, a[maxn + 67];
bool isprime[maxn + 67];
int p[maxn + 67];
vector<int> primes;
void sieve()
{
    memset(isprime, 1, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for (int i = 2; i < maxn; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < maxn; j += i)
            {
                p[j] = i;
                isprime[j] = false;
            }
        }
    }
}
int dist[maxn];
vector<int> adj[maxn];
void dijk(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (int v : adj[u])
        {
            if (d + 1 < dist[v])
            {
                dist[v] = d + 1;
                pq.push({dist[v], v});
            }
        }
    }
}
int cnt[maxn], ans[maxn];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i < maxn; i++)
    {
        for (auto p : primes)
        {
            if (i * p >= maxn)
                break;
            adj[i].push_back(i * p);
            adj[i * p].push_back(i);
        }
    }
    for (int i = 1; i < maxn; i++)
    {
        if (cnt[i])
        {
            dijk(i);
            for (int j = 1; j < maxn; j++)
            {
                if (dist[j] < 1e9)
                {
                    ans[j] += cnt[i] * dist[j];
                }
            }
        }
    }
    int res = 1e18;
    int id = 1;
    for (int j = 1; j < maxn; j++)
    {
        if (ans[j] < res)
        {
            res = ans[j];
            id = j;
        }
    }
    cout << res << " " << id << endl;
}
main()
{
    skibidi;
    file("P");
    cin >> n;
    sieve();
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
