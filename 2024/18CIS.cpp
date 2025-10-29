#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],luu,gmax=LLONG_MIN;
void sub1()
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            for (int m=1; m<=n; m++)
            {
                for (int k=1; k<=n; k++)
                {
                    for (int l=1; l<=n; l++)
                    {
                        for (int b=1; b<=n; b++)
                        {
                            if (i!=j&&i!=m&&i!=k&&i!=l&&i!=b&&j!=m&&j!=k&&j!=l&&j!=b&&m!=k&&m!=l&&m!=b&&k!=l&&k!=b&&l!=b)
                                {
                                    luu=a[i]*a[j]*a[m]+a[k]*a[l]*a[b];
                                }
                            gmax=max(gmax,luu);
                        }
                    }
                }
            }
        }
    }
    cout<<gmax;
}
void sub2()
{
    sort(a+1,a+n+1);
    if (a[1]>0)
        {
            luu=a[n]*a[n-1]*a[n-2]+a[n-3]*a[n-4]*a[n-5];
        }
    else if (a[n]<0)
        {
            luu=a[1]*a[2]*a[3]+a[4]*a[5]*a[6];
        }
    else
        {
            luu=a[n-1]*a[n-2]*a[n-3]+a[1]*a[2]*a[n];
        }
    cout<<luu;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("18CIS.INP","r",stdin);
    freopen("18CIS.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    if (n<=10)
    {
        sub1();
    }
    else
    {
        sub2();
    }
}
