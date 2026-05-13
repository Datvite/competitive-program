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
    const int N = 1e7 + 69;
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
    int n, m, k, a[N], ans[N], par[N], res = 0;
    int acs(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = acs(par[x]);
    }
    vector<iii> query;
    vector<int> rev;
    void solve()
    {
        for (int i = 1; i <= m; i++)
        {
            int l, r, c;
            cin >> l >> r >> c;
            query.push_back({c, {l, r}});
        }
        for (int i = 0; i <= n + 1; i++)
            par[i] = i;
        for (int i = 1; i <= n; ++i)
            ans[i] = 1;
        reverse(query.begin(), query.end());
        for (auto q : query)
        {
            int c = q.fi, l = q.se.fi, r = q.se.se;
            int cur = acs(l);
            while (cur <= r)
            {
                ans[cur] = c;
                par[cur] = cur + 1;
                cur = acs(cur + 1);
            }
        }
        stack<int> st;
        for (int i = 1; i <= n; i++)
        {
            while (k && !st.empty() && st.top() < ans[i])
            {
                st.pop();
                k--;
            }
            st.push(ans[i]);
        }
        while (k--)
            st.pop();
        while (!st.empty())
        {
            rev.push_back(st.top());
            st.pop();
        }
        reverse(rev.begin(), rev.end());
        for (int x : rev)
            cout << x;

    }
    main()
    {
        skibidi;
        file("FILLCHAR");
        cin >> n >> m >> k;
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
