#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll a[N],n,m,b[N];
void sol()
{
    for (int i=1; i<=m; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    sort(a+1,a+m+1);
    sort(b+1,b+n+1);
    ll l=1,r=n/2+1,ans=0,i=1;
    while(i<=m&&l<=n/2&&r<=n)
    {
        if(a[i]<=b[l])
        {
            i++;
            continue;
        }
        while(r<=n&&b[r]<=a[i])
            r++;
        if(r<=n)
            ans++;
        l++;
        r++;
        i++;
    }
    cout<<ans;
}
int main()
{
    skibidi;
    //file("ql")
    cin>>m>>n;
    sol();
}
