#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define int long long
using namespace std;
int n,a[1000068],k,m;
main()
{
    skibidi;
    //file("FISHPOOL");
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=n;i>=1;--i)
        cout<<a[i]<<" ";
}
