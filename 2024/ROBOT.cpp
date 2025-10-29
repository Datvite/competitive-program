#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll n,ans=0,maxn=0;
pair<ll,ll>a[N];
void sol()
{
    for (int i=1; i<=n; i++)
        cin>>a[i].se>>a[i].fi;
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
        if (maxn<=a[i].se)
            {
                ans++;
                maxn=max(maxn,a[i].fi);
            }
    cout<<ans;
}
main()
{
    skibidi;
    file("ROBOT")
    cin>>n;
    sol();
}

