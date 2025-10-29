#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("TOIGIAN.INP","r",stdin);
    freopen("TOIGIAN.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int t=__gcd(n,m);
    cout<<n/t<<" "<<m/t;
}
