#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("MAXPROD.INP","r",stdin);
    freopen("MAXPROD.OUT","w",stdout);
    int n;
    cin>>n;
    long long a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    long long maxv=0,t1,t2;
    sort(a,a+n);
    t1=a[0]*a[1];
    t2=a[n-1]*a[n-2];
    maxv=max(t1,t2);
    cout<<maxv;
}
