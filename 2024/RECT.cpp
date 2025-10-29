Cho cây n đỉnh, tìm cách tô các đỉnh bằng các màu từ 1 đến n thỏa mãn:
• Các đỉnh được tô cùng một màu tạo thành một đường đi.
• Gọi màu tô của đỉnh u là cu, thì dãy c1, c2, . . . , cn có thứ tự từ điển nhỏ nhất

với đề bài trên tôi code như này
#include <bits/stdc++.h>
#define task "coloring"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 5e5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

int n;
std::vector<int> adj[maxn + 7];
int color[maxn + 7], par[maxn + 7], cnt[maxn + 7];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
    {
        std::sort(adj[i].begin(), adj[i].end());
    }

    std::queue<int> q;
    int timer = 1;
    color[1] = 1;
    par[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (v == par[u])
            {
                continue;
            }
            par[v] = u;
            int used = cnt[u] + (par[u] != 0 && color[par[u]] == color[u] ? 1 : 0);
            if (used < 2)
            {
                color[v] = color[u];
                cnt[u]++;
            }
            else
            {
                timer++;
                color[v] = timer;
            }
            q.push(v);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << color[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

nhưng với test này
5
1 2
1 4
1 5
5 3

thì đúng là ra 
1 1 1 2 1
mà code tôi ra
1 1 2 1 2 

sửa lại để in ra thứ tự từ điển nhỏ nhất