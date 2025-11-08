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
    int n;
    vector<int> res;
    void ql(int cnt4, int cnt7, int val)
    {
        if (val > 1e12)
            return;
        if (cnt4 == cnt7)
            res.push_back(val);
        ql(cnt4 + 1, cnt7, val * 10 + 4);
        ql(cnt4, cnt7 + 1, val * 10 + 7);
    }
    void solve()
    {
        ql(0, 0, 0);
        sort(res.begin(), res.end());
        cin >> n;
        cout << *lower_bound(res.begin(), res.end(), n) << endl;
    }
    main()
    {
        skibidi;
        file("");
        solve();
    }
