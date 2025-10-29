#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("ANTS.INP","r",stdin);
    freopen("ANTS.OUT","w",stdout);
    int n;
    long long k;
    cin>>n>>k;
    long long a[n],maxvalua=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int b[3000009];
    for (int i=0;i<n;i++)
    {
        if (a[i]>0)
        {
            maxvalua=max(maxvalua,(k-a[i]));
        }
        if (a[i]<0)
        {
            maxvalua=max(maxvalua,-a[i]);
        }
    }
    cout<<maxvalua;
}
