#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("EVEN11.INP","r",stdin);
    freopen("EVEN11.OUT","w",stdout);
    long long n,maxv=0,t,dem=0,a;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a;
        if (a>0&&a%2==0)
        {
            dem++;
        }
        else
        {
            if (dem>maxv)
            {
                maxv=dem;
                t=i-dem;
            }
            dem=0;
        }
    }
    if (dem>maxv)
    {
        maxv=dem;
        t=n-dem+1;
    }
    if (maxv!=0)
    cout<<maxv<<endl<<t;
    else
        cout<<0<<endl<<0;
}
