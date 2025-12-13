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
    int n, m, ans = 0, s[N];
    // knapsack 1
    ii a[N];
    vector<int> v, res;
    void Try(int id, int w, int val)
    {
        if (w > m || val + s[n] - s[id - 1] < ans)
            return;
        if (id > n)
        {
            if (val > ans)
            {
                ans = val;
                res = v;
            }
            return;
        }
        if (w + a[id].fi <= m)
            {
                v.push_back(id);
                Try(id + 1, w + a[id].fi, val + a[id].se);
                v.pop_back();
            }
        Try(id + 1, w, val);
    }
    void solve()
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].fi >> a[i].se;
            s[i] = s[i - 1] + a[i].se;
        }
        Try(1, 0, 0);
        cout << ans << endl;
        for (auto x : res)
            cout << x << " ";
    }
    main()
    {
        skibidi;
        file("KSACK1");
        cin >> n >> m;
        solve();
    }
