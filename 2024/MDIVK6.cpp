#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("MDIVK6.INP","r",stdin);
    freopen("MDIVK6.OUT","w",stdout);
    long long n,k,a[1000068];
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=n;i>=1;i--)
    {
        if (a[i]%k==0)
        {
            cout<<a[i];
            return 0;
        }
    }

}
