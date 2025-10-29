#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("DECLARR.INP","r",stdin);
    freopen("DECLARR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,tong=0,dem=0;
    int a[3000000];
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        tong=tong+a[i];
    }
    sort(a,a+n);
    int m=n-1,t=0;
    while (tong!=0)
    {
        if (tong>0)
        {
            tong=tong-a[m];
            m--;
            dem++;
        }
        if (tong<0)
        {
            tong=tong-a[t];
            t++;
            dem++;
        }
    }
    cout<<dem;
}
