#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("DXB1.INP","r",stdin);
    freopen("DXB1.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,m,x=0,t=0,s=0;
    cin>>n>>m;
    s=(n/2)*m;
    if (n%2==0)
        cout<<s<<" "<<s;
    else
        cout<<s+m<<" "<<s;
}
