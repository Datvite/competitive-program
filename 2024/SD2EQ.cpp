#include<bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;

#define int long long
const int N = 1e6 + 6;
int n, a[N], k, s[N], minn[N];

int solve(int l, int r, int k)
{
    if (k == 1)
    {
        int min_val = LLONG_MAX;
        for (int i = l; i <= r; i++)
        {
            min_val = min(min_val, s[i] - s[l - 1]);
        }
        return min_val;
    }

    int mid = (l + r) / 2;
    int left = solve(l, mid, k - 1);
    int right = solve(mid + 1, r, k - 1);

    return max(left, right);
}

main()
{
    skibidi
    file("SDKEQ")
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    cout << solve(1, n, k);
    return 0;
}
