#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=4e6+69;
ll a[N],n,ans[N];
ll m[N];
void sol()
{
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            ans[j]+=m[-a[i]+a[j]+2000000];
        }
        for(int j=1; j<=i-1; j++)
        {
            m[a[i]+a[j]+2000000]++;
        }
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
}
int main()
{
    skibidi;
    file("TOTAL3")
    cin>>n;
    sol();
}

