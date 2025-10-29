#include<bits/stdc++.h>
using namespace std;
long long n,dem=0;
long long t=0;
int a[10000000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("SXDS.INP","r",stdin);
    freopen("SXDS.OUT","w",stdout);
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];

    }
    for (int i=0;i<n;i++)
    {
        if (a[i]%2!=0)
            dem++;
    }
    for (int i=0;i<dem;i++)
    {
        if (a[i]%2==0)
            t++;
    }
    cout<<t;
}
