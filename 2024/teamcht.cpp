#include<bits/stdc++.h>
using namespace std;
long long n,a[1000068],s[1000068],dem=0,k,m;
int main()
{
    cin>>n>>k;
    s[0]=0;
    for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
    sort(s+1,s+n);
    for (int i=1;i<=n;i++)
        {
            m=s[i]-k;
            if (binary_search(s+1,s+n,m))
                dem++;
        }
    cout<<dem;
}
