#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("DIST11.INP","r",stdin);
    freopen("DIST11.OUT","w",stdout);
    long long n,a,maxv=LLONG_MIN,minv=LLONG_MAX;
    cin>>n;
    for (int i=1;i<=n;i++)
        {
            cin>>a;
            minv=min(minv,a);
            maxv=max(maxv,a);
        }
    cout<<abs(minv-maxv);
}
