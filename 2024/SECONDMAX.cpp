#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("SECONDMAX.INP","r",stdin);
    freopen("SECONDMAX.OUT","w",stdout);
    long long n;
    int maxvalua=0;
    cin>>n;
    int a[3000009],b[3000009];
    for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
            maxvalua=max(maxvalua,a[i]);
        }
    sort (a+1,a+n+1);
    int k = lower_bound(a, a + n, maxvalua)-a-1;
    cout<<a[k]<<endl;
    for (int i=1;i<=n;i++)
    {
        if (b[i]==a[k])
            cout<<i<<" ";
    }
}
