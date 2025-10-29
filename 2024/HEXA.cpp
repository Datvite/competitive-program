#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
long long a[10],d[1000068],j,ans,n,s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (long long i=2; i<=n; ++i)
    {
        j=i;
        s=2;
        while (j>1&&j%5==0)
            {
                j=j/5;
        a[1]++;
            }
        while (j>1&&j%2==0)
            {
                j=j/2;
        a[2]++;
            }
    }
    if (a[1]>=a[2])
        a[1]=a[2];
    else
        a[2]=a[1];
    ans=a[1]+a[2];
    ans=ans/2;
    cout<<ans;
}
