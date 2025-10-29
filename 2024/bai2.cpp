#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define int long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll n,ans=0,check=0;
pair<int,int>a[N];
bool cmp (pair<int,int>a,pair<int,int>b)
{
    return a.se<b.se;
}
void sol1()
{
    for (int i=1; i<=n; i++)
        cin>>a[i].fi>>a[i].se;
    sort(a+1,a+n+1,cmp);
    for (int i=2; i<=n; i++)
    {
        if (a[i].fi>a[i-1].se)
            ans+=a[i].fi-a[i-1].se-1;
    }
    cout<<ans;
}
void sol2()
{
    ll f[N],maxn=LLONG_MIN,res=0,minn=LLONG_MAX;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].fi>>a[i].se;
        f[a[i].fi]++;
        f[a[i].se+1]--;
        maxn=max(maxn,a[i].se);
        minn=min(minn,a[i].fi);
    }
    for (int i=minn; i<=maxn; i++)
        f[i]+=f[i-1];
    for (int i=minn; i<=maxn; i++)
        if (!f[i])
            res++;
    cout<<res<<endl;
}
main()
{
    skibidi;
    file("SPOR")
    cin>>n;
    sol1();
}
