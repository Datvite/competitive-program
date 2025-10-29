#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69,mod=1e9+7;
ll a[N],n,ans=0,dem=0,f[N],res=0,K;
void sol()
{
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=n-2; i++)
    {
        int l = i + 2,r=n,k=i;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] - a[i] <= k) {
                k = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        while (k<=n&&a[k]-a[i]<=K)
        {
            if (k-i-1>=1)
                ans+=(k-i-1);
            k++;
        }
    }
    cout<<ans;
}
int main()
{
    skibidi;
    file("BBCANBANG")
    cin>>n>>K;
    sol();
}
