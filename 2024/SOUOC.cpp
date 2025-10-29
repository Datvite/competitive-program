#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SOUOC.INP","r",stdin);
    freopen("SOUOC.OUT","w",stdout);
    long long n,s=0,m;
    cin>>n;
    if (n==1)
        s=1;
    for (int i=1;i<=n/2;i=i+2)
    {
        if (n%i==0)
        {
            s++;
        }
    }
    cout<<s;
}
