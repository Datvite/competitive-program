#include <bits/stdc++.h>
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
using namespace std;
long long x,y,z,ans;
signed main()
{
    file("MDL");
    cin>>x>>y>>z;
    ans=x*y;
    cout<<(ans%z+z)%z;
}
