#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll a[N],n,k;
bool check(ll mid)
{
    ll sum[N];
    for (int i=1; i<=n; i++)
    {
        if (mid<=a[i])
            sum[i]=1;
        else
            sum[i]=-1;
        sum[i]+=sum[i-1];
    }
    ll maxn=sum[k],minn=0;
    for (int i=k; i<=n; i++)
    {
        minn=min(minn,sum[i-k]);
        maxn=max(maxn,sum[i]-minn);
    }
    return maxn>0;
}
void sol()
{
    for(int i=1; i<=n; i++)
        cin>>a[i];
    ll l=1,r=1e18,ans;
    while(l<=r)
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
}
int main()
{
    skibidi;
    //file("ql")
    cin>>n>>k;
    sol();
}

