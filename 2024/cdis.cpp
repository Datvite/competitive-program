#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69,mod=1e9+7;
ll a[N],n,ans=0,dem=0,f[N],res=0;
void sol2()
{
    ll m[N],dp[N];
    f[0]=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        dp[i]=dp[i-1]%mod+i%mod-m[a[i]]%mod;
        m[a[i]]=i;
        ans+=dp[i]%mod;
        ans=ans%mod;
    }
    cout<<ans%mod;
}
int main()
{
    skibidi;
    file("TBFOREST")
    cin>>n;
    sol2();
}
