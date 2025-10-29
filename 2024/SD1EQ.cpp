#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll a[N],n,s[N],s1[N],minn[N],minn1[N],f[N],f1[N],b[N],luu=LLONG_MIN;
void sol()
{
    s[0]=s1[n+1]=0;
    minn[0]=minn1[n+1]=0;
    f[0]=f1[n+1]=LLONG_MIN;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        minn[i]=min(minn[i-1],s[i]);
        f[i]=max(f[i-1],s[i]-minn[i-1]);
    }
    for (int i=n; i>=1; --i)
    {
        s1[i]=s1[i+1]+a[i];
        minn1[i]=min(minn1[i+1],s1[i]);
        f1[i]=max(f1[i+1],s1[i]-minn1[i+1]);
    }
    ll luu=LLONG_MIN;
    for (int i=1; i<n; ++i)
    {
        luu=max(luu,f[i]+f1[i+1]);
    }
    cout<<luu;
}
int main()
{
    skibidi;
    file("MXS")
    cin>>n;
    sol();
}

