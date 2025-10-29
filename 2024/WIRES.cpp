#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll a[N],n,b[N],k;
unordered_map<ll,ll>m;
bool check(ll mid)
{
    ll dem=0;
    for (int i=1;i<=n;i++)
        {
            dem+=a[i]/mid;
            if (dem>=k)
                return 1;
        }
    return 0;
}
void sol()
{
    for (int i=1;i<=n;i++)
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
    file("PART")
    cin>>n>>k;
    sol();
}

