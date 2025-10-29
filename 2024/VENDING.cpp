#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define N 1000068
#define for(i,l,r) for (long long i=l;i<=r;i++)
using namespace std;
long long n;
long long a[1000068],ans=1;
map<int,bool>m;
int main()
{
    skibidi;
    file("VENDING");
    cin>>n;
    for (i,1,n)
    {
        cin>>a[i];
        if (ans<a[i])
            break;
        ans+=a[i];
    }
    cout<<ans;
}
