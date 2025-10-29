#include <bits/stdc++.h>
#define endl "\n"
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
using namespace std;
long long t,a[1000068],n,k,ans=0;
map<int,int>m;
void sol()
{
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>k;
        cout<<m[k]<<endl;
    }
}
int main()
{
    skibidi;
    //file("DPAIRS");
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
