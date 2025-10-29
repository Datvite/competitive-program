#include <bits/stdc++.h>
using namespace std;
long long n,a,b,c,d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("DOANTHANGTS.INP","r",stdin);
    freopen("DOANTHANGTS.OUT","w",stdout);
    cin>>a>>b>>c>>d;
    if (a<=c&&c<=b||c<=a&&a<=d||a<=d&&d<=b||c<=b&&b<=d)
        cout<<"YES";
    else
        cout<<"NO";
}
