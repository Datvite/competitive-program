#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
#define gcd(a,b) __gcd(a,b)
using namespace std;
const int N=1e6+69;
ll lcm(ll a,ll b)
{
    return a*b/__gcd(a,b);
}
ll a,b,c,n,m,k;
bool check(ll mid)
{
    ll s=0;
    for(int i=1; i<=m; i++)
    {
        ll j=sqrt(mid-i*i);
        if(j>=1)
        {
            s+=min(j,n);
        }
        if(s>=k) return true;
    }
    return false;
}
void sol()
{
    ll l=1,r=1e18,ans;
    while (l<=r)
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
    file("NUMORDER")
    skibidi;
    cin>>m>>n>>k;
    sol();
}

