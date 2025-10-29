#include <bits/stdc++.h>
using namespace std;
long long a[1000068];
int n,i,j;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int m=1; m<=n; m++)
    {
        a[m]=m;
             cout<<m<<" ";
    }
    cout<<endl;
    i=n-1;
    while (i>=1)
    {
        i=n-1;
        while (a[i]>a[i+1])
            {
                --i;
            }
        if (i<1)
            return 0;
        j=n;
        while (a[i]>a[j])
            --j;
        swap(a[i],a[j]);
        reverse(a+i+1,a+n+1);
        for (int m=1; m<=n; m++)
        {
            cout<<a[m]<<" ";
        }
        cout<<endl;
    }
}
