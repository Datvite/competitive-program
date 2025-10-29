#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SMIN.INP","r",stdin);
    freopen("SMIN.OUT","w",stdout);
    long long n;
    cin>>n;
    long long a[1000009];
    long long b[1000009];
    for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    for (int i=1;i<=n;i++)
    {
        if (binary_search(a,a+n,i))
        {
            cout<<i;
            return 0;
        }
    }
    cout<<n+1;
}
