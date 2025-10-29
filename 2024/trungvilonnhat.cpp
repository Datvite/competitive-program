#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll a[N],n,m;
bool check(ll mid)
{
    ll dem=0;
    for (ll i=n/2+1;i<=n;i++)
        {
            dem+=mid-a[i];
            if (dem>m)
                return false;
        }
    return true;
}
void sol()
{
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll l=1,r=1e18,ans=0;
    while (l<=r)
        {
            ll mid=(l+r)/2;
            if (check(mid))
                {
                    ans=mid;
                    l=mid+1;
                }
            else
                r=mid-1;
        }
    cout<<ans;
    /*8 8
      8 8 8 8 8 8 8 8
    */
}
int main()
{
    skibidi;
    //file("ql")
    cin>>n>>m;
    sol();
}

