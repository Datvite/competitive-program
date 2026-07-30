#include <bits/stdc++.h>
using namespace std;

int n, q, t, l, r, x;
vector<int> a;

struct Node
{
    int sum;
    int mn, cntmn, mx, cntmx;
    int gcd_val, cntgcd;
    long long lcm_val;
    int cntlcm;
    int cnt_val[51];
};

vector<Node> it;
vector<int> lazy;

Node merge_node( Node l, Node r )
{
    if (l.mn == 2e9) return r;
    if (r.mn == 2e9) return l;
    Node p;
    p.sum = l.sum + r.sum;

    if (l.mn < r.mn)
    {
        p.mn = l.mn;
        p.cntmn = l.cntmn;
    }
    else if (l.mn > r.mn)
    {
        p.mn = r.mn;
        p.cntmn = r.cntmn;
    }
    else
    {
        p.mn = l.mn;
        p.cntmn = l.cntmn + r.cntmn;
    }

    if (l.mx > r.mx)
    {
        p.mx = l.mx;
        p.cntmx = l.cntmx;
    }
    else if (l.mx < r.mx)
    {
        p.mx = r.mx;
        p.cntmx = r.cntmx;
    }
    else
    {
        p.mx = l.mx;
        p.cntmx = l.cntmx + r.cntmx;
    }

    p.gcd_val = std::gcd(l.gcd_val, r.gcd_val);
    p.lcm_val = std::lcm(l.lcm_val, r.lcm_val);

    p.cntgcd = 0;
    p.cntlcm = 0;
    for (int i = 1; i <= 50; i++)
    {
        p.cnt_val[i] = l.cnt_val[i] + r.cnt_val[i];
        if (p.gcd_val == i)
            p.cntgcd += p.cnt_val[i];
        if (p.lcm_val == i)
            p.cntlcm += p.cnt_val[i];
    }
  return p;
}

void build( int id, int l, int r )
{
    if ( l == r )
    {
        it[id].sum = it[id].mn = it[id].mx = it[id].gcd_val = it[id].lcm_val = a[l];
        it[id].cntmn = it[id].cntmx = it[id].cntgcd = it[id].cntlcm = 1;
        memset(it[id].cnt_val, 0, sizeof(it[id].cnt_val));
        it[id].cnt_val[a[l]] = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build( id*2, l, mid );
    build( id*2+1, mid+1, r );
    it[id] = merge_node(it[id*2], it[id*2+1]);
}

void apply_lazy(int id, int l, int r, int val)
{
    int len = (r - l + 1);
    it[id].sum = val * len;
    it[id].mn = it[id].mx = it[id].gcd_val = it[id].lcm_val = val;
    it[id].cntmn = it[id].cntmx = it[id].cntgcd = it[id].cntlcm = len;
    memset(it[id].cnt_val, 0, sizeof(it[id].cnt_val));
    it[id].cnt_val[val] = len;

    lazy[id] = val;
}

void push( int id, int l, int r )
{
    if ( lazy[id] )
    {
        int mid = (l + r) >> 1;
        apply_lazy(id*2, l, mid, lazy[id]);
        apply_lazy(id*2+1, mid+1, r, lazy[id]);
    }
    lazy[id] = 0;
}

void update( int id, int l, int r, int u, int v, int val )
{
    if ( l > v || r < u )
        return;
    if ( l >= u && r <= v )
    {
        apply_lazy( id, l, r, val );
      return;
    }
    push(id, l, r);
    int mid = (l + r) >> 1;
    update( id*2, l, mid, u, v, val );
    update( id*2+1, mid+1, r, u, v, val );
    it[id] = merge_node( it[id*2], it[id*2+1] );
}

Node query( int id, int l, int r, int u, int v )
{
    if ( l > v || r < u )
    {
        Node empty_node;
        empty_node.mn = 2e9;
        empty_node.lcm_val = 1;
      return empty_node;
    }
    if ( l >= u && r <= v )
        return it[id];
    push(id, l, r);
    int mid = (l + r) >> 1;
    return merge_node(query(id * 2, l, mid, u, v), query(id * 2 + 1, mid + 1, r, u, v));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    a.resize(n+1);
    it.resize(4*n+1);
    lazy.resize(4*n+1);
    for ( int i = 1; i <= n; i++ )
        cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        cin >> t;
        if ( t == 1 )
        {
            cin >> l >> r >> x;
            update( 1, 1, n, l, r, x );
        }
        else
        {
            cin >> l >> r;
            Node res = query(1, 1, n, l, r);
            switch (t) {
                case 2 : cout << res.sum << "\n"; break;
                case 3 : cout << res.mn << "\n"; break;
                case 4 : cout << res.cntmn << "\n"; break;
                case 5 : cout << res.mx << "\n"; break;
                case 6 : cout << res.cntmx << "\n"; break;
                case 7 : cout << res.gcd_val << "\n"; break;
                case 8 : cout << res.cntgcd << "\n"; break;
                case 9 : cout << res.lcm_val << "\n"; break;
                case 10 : cout << res.cntlcm << "\n"; break;
            }
        }
    }
  return 0;
}