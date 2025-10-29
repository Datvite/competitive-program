#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("INCSEG.INP","r",stdin);
    //freopen("INCSEG.OUT","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    int maxv=0;
    int hientai=1;
    for (int i=0;i<n;i++)
    {
        if (a[i]<=a[i+1])
        {
            hientai++;
            maxv=max(maxv,hientai);
        }
        else
            hientai=1;
    }
    cout<<maxv;
}
