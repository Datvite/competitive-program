#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CINT12.INP","r",stdin);
    freopen("CINT12.OUT","w",stdout);
    long long a,b,c,d,n;
    cin>>a>>b>>c>>d;
    if (b<c||d<a)
        {
            cout<<b-a+d-c+2;
            return 0;
        }
    cout<<max(b,d)-min(a,c)+1;
}
