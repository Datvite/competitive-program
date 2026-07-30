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
const int LOG = 30;
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
int n, q, a[N];
struct Trie
{
    struct Node
    {
        int child[2];
        int cntEnd;
        int cntPass;

        Node()
        {
            memset(child, -1, sizeof(child));
            cntEnd = cntPass = 0;
        }
    };

    vector<Node> trie;

    Trie()
    {
        trie.emplace_back();    
    }

    void insert(int x)
    {
        int u = 0;
        trie[u].cntPass++;
        for (int i = LOG; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            if (trie[u].child[bit] == -1)
            {
                trie[u].child[bit] = trie.size();
                trie.emplace_back();
            }
            u = trie[u].child[bit];
            trie[u].cntPass++;
        }
        trie[u].cntEnd++;
    }
    void erase(int x)
    {
        int u = 0;
        trie[u].cntPass--;
        for (int i = LOG; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            u = trie[u].child[bit];
            trie[u].cntPass--;
        }
        trie[u].cntEnd--;
        return;
    }
    int get(int x)
    {
        int u = 0, res = 0;
        for (int i = LOG; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            if (trie[u].child[bit ^ 1] != -1 && trie[trie[u].child[bit ^ 1]].cntPass > 0)
            {
                res |= (1LL << i);
                u = trie[u].child[bit ^ 1];
            }
            else
            {
                u = trie[u].child[bit];
            }
        }
        return res;
    }
};
void solve()
{
    Trie trie;
    trie.insert(0);
    while(q--)
    {
        char t;
        int x;
        cin >> t >> x;
        if (t == '+')
            trie.insert(x);
        else if (t == '-')
            trie.erase(x);
        else
            cout << trie.get(x) << endl;
    }
}
main()
{
    skibidi;
    file("");
    cin >> q;
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
