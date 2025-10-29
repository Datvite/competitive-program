#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#pragma GCC optimize("Ofast")
using namespace std;
long long t,a[1000068],n,k,m,ans,minn,maxn=LLONG_MIN;
void sol()
{
    for (int i=1;i<=n;i++)
        cin>>a[i];
    minn=a[1];
    for (int i=2;i<=n;i++)
        {
            maxn=max(maxn,a[i]-minn);
            minn=min(minn,a[i]);
        }
    cout<<maxn;
}
int main()
{
    skibidi;
    file("DIFM");
    cin>>n;
    sol();
}

/*
2
6 2 12
1 4 6 8 9 11
3 2 20
1 2 4

*/
