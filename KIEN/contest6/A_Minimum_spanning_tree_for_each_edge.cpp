#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define int long long
#define endl "\n"
using namespace std;

struct node
{
    int pref, suf, sum, maxn, pref2, suf2, minn;
    node()
    {
        // Khởi tạo node rỗng (identity node) hợp lý với đoạn rỗng = 0
        sum = 0;
        pref = suf = maxn = 0;
        pref2 = suf2 = minn = 0;
    }
    node(int x)
    {
        sum = x;
        // Đoạn con có thể rỗng nên phải lấy max/min với 0
        maxn = max(0LL, x);
        pref = suf = max(0LL, x);
        minn = min(0LL, x);
        pref2 = suf2 = min(0LL, x);
    }
};

node merge(node a, node b)
{
    node res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref, a.sum + b.pref);
    res.suf = max(b.suf, b.sum + a.suf);
    res.maxn = max({a.maxn, b.maxn, a.suf + b.pref});
    res.pref2 = min(a.pref2, a.sum + b.pref2);
    res.suf2 = min(b.suf2, b.sum + a.suf2);
    res.minn = min({a.minn, b.minn, a.suf2 + b.pref2});
    return res;
}

struct LCA
{
    static const int LOG = 20;
    int n;
    vector<vector<int>> up;
    vector<vector<node>> val;
    vector<int> depth;

    LCA(int _n)
    {
        n = _n;
        up.assign(n + 1, vector<int>(LOG, 0));
        val.assign(n + 1, vector<node>(LOG));
        depth.assign(n + 1, 0);
    }

    void init(int root, int val_root)
    {
        depth[root] = 0;
        node r_node = node(val_root);
        for (int j = 0; j < LOG; j++)
        {
            up[root][j] = root;
            val[root][j] = r_node; // Cha của gốc là chính nó, node không đổi
        }
    }

    void add_node(int u, int v, int value)
    {
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        val[v][0] = node(value);
        for (int j = 1; j < LOG; j++)
        {
            up[v][j] = up[up[v][j - 1]][j - 1];
            // Lưu ý thứ tự gộp: val[v][j-1] ở dưới (gần v hơn), up[v][j-1] ở trên
            val[v][j] = merge(val[v][j - 1], val[up[v][j - 1]][j - 1]);
        }
    }

    node get(int u, int v)
    {
        // Thu thập các đoạn thuộc nhánh u (đi lên) và nhánh v (đi lên)
        vector<node> left_nodes, right_nodes;

        if (depth[u] < depth[v])
        {
            int k = depth[v] - depth[u];
            for (int i = LOG - 1; i >= 0; i--)
            {
                if ((k >> i) & 1)
                {
                    right_nodes.push_back(val[v][i]);
                    v = up[v][i];
                }
            }
        }
        else if (depth[u] > depth[v])
        {
            int k = depth[u] - depth[v];
            for (int i = LOG - 1; i >= 0; i--)
            {
                if ((k >> i) & 1)
                {
                    left_nodes.push_back(val[u][i]);
                    u = up[u][i];
                }
            }
        }

        if (u == v)
        {
            left_nodes.push_back(val[u][0]); // Thêm đỉnh chung LCA
        }
        else
        {
            for (int i = LOG - 1; i >= 0; i--)
            {
                if (up[u][i] != up[v][i])
                {
                    left_nodes.push_back(val[u][i]);
                    right_nodes.push_back(val[v][i]);
                    u = up[u][i];
                    v = up[v][i];
                }
            }
            left_nodes.push_back(val[u][0]);
            right_nodes.push_back(val[v][0]);
            left_nodes.push_back(val[up[u][0]][0]); // Thêm đỉnh cha chung (LCA)
        }

        // Gộp nhánh bên trái: đi từ u lên LCA công thức xuôi dòng gộp liên tiếp
        node res_left; 
        if(!left_nodes.empty()){
            res_left = left_nodes[0];
            for(size_t i = 1; i < left_nodes.size(); i++) {
                res_left = merge(res_left, left_nodes[i]);
            }
        }

        // Gộp nhánh bên phải: đi từ LCA xuống v 
        // Vì ta thu thập từ v lên LCA, nên để đi từ LCA -> v ta phải lật ngược mảng và đổi hướng sinh đoạn con khi merge
        node res_right;
        if(!right_nodes.empty()){
            // Để đi từ LCA xuống v, ta lật ngược right_nodes lại
            reverse(right_nodes.begin(), right_nodes.end());
            res_right = right_nodes[0];
            for(size_t i = 1; i < right_nodes.size(); i++) {
                res_right = merge(res_right, right_nodes[i]);
            }
            // Gộp nhánh trái (u -> LCA) với nhánh phải (LCA -> v)
            return merge(res_left, res_right);
        }

        return res_left;
    }
};

void solve()
{
    int q;
    cin >> q;
    LCA lca(200005);
    lca.init(1, 1);
    int cur = 1;
    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == '+')
        {
            int x, val;
            cin >> x >> val;
            cur++;
            lca.add_node(x, cur, val);
        }
        else
        {
            int u, v, k;
            cin >> u >> v >> k;
            node ans = lca.get(u, v);
            if (ans.minn <= k && k <= ans.maxn)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}

int32_t main()
{
    skibidi;
    int t;
    if (cin >> t)
    {
        while (t--)
            solve();
    }
    return 0;
}