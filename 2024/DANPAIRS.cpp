#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll a[N],cntx,cnty,x,y,b[N];
bool check(ll mid)
{
    ll dx=mid-mid/x,dy=mid-mid/y,dxy=mid-mid/(x*y);
    ll ansxy=dx+dy-dxy;
    dx-=ansxy,dy-=ansxy;
    if (dx<cntx)
    ansxy=ansxy-(cntx-dx);
    if (dy<cnty)
    ansxy=ansxy-(cnty-dy);
    if (ansxy>=0)
        return 1;
    else
        return 0;
}
void sol()
{
    cin>>cntx>>cnty>>x>>y;
    ll l=1,r=1e18,ans;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans;
}
int main()
{
    skibidi;
    file("FRPR")
    sol();
}
