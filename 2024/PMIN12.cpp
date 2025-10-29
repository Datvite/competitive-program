#include<bits/stdc++.h>
using namespace std;
long long n,a[1000086],b[1000086],luu1,luu2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PMIN12.INP","r",stdin);
    freopen("PMIN12.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    if (b[1]>0)
    {
        for (int i=1; i<=n; i++)
        {
            if (b[1]==a[i])
                luu1=i;
            if (b[2]==a[i])
                luu2=i;
        }
        cout<<luu1<<" "<<luu2;
    }
    else if (b[n]<0)
    {
        for (int i=1; i<=n; i++)
        {
            if (b[n]==a[i])
                luu1=i;
            if (b[n-1]==a[i])
                luu2=i;
        }
        cout<<luu1<<" "<<luu2;
    }
    else
    {
        for (int i=1; i<=n; i++)
        {
            if (b[1]==a[i])
                luu1=i;
            if (b[n]==a[i])
                luu2=i;
        }
        cout<<luu1<<" "<<luu2;
    }
}

