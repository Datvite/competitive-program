#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll n,a[N],b[N],sum[N],l,r,dem=0;
void sol()
{
    sum[0]=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    sort(sum,sum+n+1);
    ll j=0,k=0;
    for (int i=0; i<=n; i++)
    {
        if (j<=i)
            j=i+1;
        if (k<=i)
            k=i+1;
        while(j<=n&&sum[j]-sum[i]<l)
            j++;
        while(k<=n&&sum[k]-sum[i]<=r)
            k++;
        dem+=k-j;
    }
    cout<<dem;
}
int main()
{
    skibidi;
    file("SBOUND")
    cin>>n>>l>>r;
    sol();
}
