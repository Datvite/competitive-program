#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define int long long
using namespace std;
int n,k,a[2000068],m,d1,d2,ans=0;
main()
{
    skibidi;
    cin>>n;
    for (int i=1; i<=n; ++i)
        {
            cin>>a[i];
            m=a[1];
            ans+=abs(m-a[i]);
        }
    cout<<ans<<" ";
    d1=1;
    d2=n-1;
    for (int i=2; i<=n; ++i)
        {
            m=a[i]-a[i-1];
            ans+=d1*m-d2*m;
            d1++;
            d2--;
            cout<<ans<<" ";
        }

}
