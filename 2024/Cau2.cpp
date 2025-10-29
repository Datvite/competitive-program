#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll a[N],n,ans=0,k;
unordered_map<ll,ll>m;
void sol()
{
    for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            ans+=m[k-a[i]];
            m[a[i]]++;
        }
    cout<<ans;
}
main()
{
    skibidi;
    //file("ql")
    cin>>n>>k;
    sol();
}

