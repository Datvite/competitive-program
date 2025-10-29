#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],dem=0,gmax=LLONG_MIN,b[1000068],luu=0;
void sub1()
{
    a[0]=LLONG_MAX;
    a[n+1]=LLONG_MAX;
    if (a[1]<a[2])
    for (int i=1; i<=n; i++)
    {
        dem=0;
        for (int j=i; j>=1; j--)
        {
            if (a[j]>a[j-1])
            {
                dem++;
            }
            else
            {
                if (dem>0)
                    dem++;
                else
                    break;
                for (int k=i; k<=n; k++)
                {
                    if (a[k]>a[k+1])
                    {
                        dem++;
                        gmax=max(gmax,dem);
                    }
                    else
                        break;
                }
            }
        }
    }
    else
        for (int i=1; i<=n; i++)
    {
        dem=0;
        for (int j=i; j>1; j--)
        {
            if (a[j]>a[j-1])
            {
                dem++;
            }
            else
            {
                if (dem>0)
                    dem++;
                else
                    break;
                for (int k=i; k<=n; k++)
                {
                    if (a[k]>a[k+1])
                    {
                        dem++;
                        gmax=max(gmax,dem);
                    }
                    else
                        break;
                }
            }
        }
    }
    cout<<gmax;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("19COS.INP","r",stdin);
    freopen("19COS.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sub1();
}
