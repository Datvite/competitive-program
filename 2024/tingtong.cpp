#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=2e6+69;
ll a[N],n,sum[N],q;
void sol()
{
    sum[0]=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum[i]+=sum[i-1]+a[i];
    }
    for (int i=1; i<=q; i++)
    {
        ll k,l,ans=0;
        cin>>k>>l;
        l=(l-1)%n;
        if (l+k<=n)
            ans=sum[l+k]-sum[l];
        else
        {
            ans=sum[n]-sum[l];

            k=k-(n-l);
            ll t=k/n;
            ans+=sum[n]*t;
            if (k%n==0)
                ans-=sum[n];
            k=k%n;
            if (k==0)
                {
                    k=n;
                }
            ans+=sum[k];
        }
        cout<<ans<<endl;
    }
}
int main()
{
    skibidi;
    //freopen ("aaa.inp","r",stdin);
    //freopen ("aaa.out","w",stdout);
    cin>>n>>q;
    sol();
}

