#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DNUM6.INP","r",stdin);
    freopen("DNUM6.OUT","w",stdout);
    int n,m,a[1000068],b[1000068],dem=0,luu;
    cin>>n>>m;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<m; i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    if (n>=m)
    {
        for (int i=0; i<n; i++)
        {
            if (a[i]!=luu)
            {
                if (binary_search(b,b+m,a[i]))
                {
                    luu=a[i];
                    if ((upper_bound(b,b+m,a[i])-lower_bound(b,b+m,a[i]))<(upper_bound(a,a+n,a[i])-lower_bound(a,a+n,a[i])))
                        dem=dem+upper_bound(b,b+n,a[i])-lower_bound(b,b+n,a[i]);
                    else
                        dem=dem+(upper_bound(a,a+n,a[i])-lower_bound(a,a+n,a[i]));
                }
            }
        }
    }
    else
        {
        for (int i=0; i<m; i++)
        {
            if (b[i]!=luu)
            {
                if (binary_search(a,a+n,b[i]))
                {
                    luu=b[i];
                    if ((upper_bound(a,a+n,b[i])-lower_bound(a,a+n,b[i]))<(upper_bound(b,b+m,b[i])-lower_bound(b,b+m,b[i])))
                        dem=dem+upper_bound(a,a+m,b[i])-lower_bound(a,a+m,b[i]);
                    else
                        dem=dem+(upper_bound(b,b+m,b[i])-lower_bound(b,b+m,b[i]));
                }
            }
        }
    }
        cout<<dem;
}
