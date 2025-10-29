#include<bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=1e6+5,mod=1e9;
int n,q,m;
ll f[N],a[N],b[N],c[N];
main()
{
    skibidi
    file("UDTSEQ2")
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        ll l,r,u,v,k;
        cin>>l>>r>>k;
        a[l]+=k;
        a[r+1]-=k;
        b[r+1]+=(r-l+1)*k;
    }
    for(int i=1; i<=n; i++)
    {
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    for(int i=1; i<=n; i++)
    {
        a[i]+=a[i-1];
    }
    for(int i=1; i<=n; i++)
    {
        ll k=a[i]%mod-b[i]%mod;
        cout<<(k%mod+mod)%mod<<" ";
    }
}
/*5 3
1 5 1
2 3 2
1 5 3
*/
// 1 2 3 4 5
// 0 2 4 0 0
// 3 6 9 12 15



//                     i=5
// 1 +1  5   3 +1  4 +1 5 +1   di=1,i+2,i+3,i+4,i+i,i
// di =di-1 +i - mai
//mai=i
