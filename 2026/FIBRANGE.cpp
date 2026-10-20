#include<bits/stdc++.h> 
using namespace std;
#define task "DIVSEG"
#define ilovemygfsfeet int main()
#define pb push_back
#define ins insert
#define fi first
#define se second
typedef long long ll;
const int N = 1e6 + 9;
const int MOD = 1e9 + 7;
ll q, l, r, d, minn, b, k, p, n, m;
ilovemygfsfeet
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> q;
    while (q--)
    {
        cin >> l >> r >> d;
        b = -1;
        minn = -1;
        p = d;
        k = 1;
        while (p <= r)
        {
            m = (l + p - 1) / p;
            n = m * p;
            if (n <= r)
            {
                b = k;
                minn = n;
            }
            else
                break;
            if (r / d < p)
                break;
            p = d;
            k++;
        }
        if (b == -1)
            cout << -1 << '\n';
        else
            cout << b << ' ' << minn << '\n';
    }
    return 0;
}