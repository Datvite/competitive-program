#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],dem=0;
bool snt (long long n)
{
    if (n<2)
        return false;
    for (long long i=2; i<=sqrt(n); i++)
    {
        if (n%i==0)
            return false;
    }
    return true;
}
int main()
{
    freopen("SPRIME.INP","r",stdin);
    freopen("SPRIME.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=2; i<=n; i++)
    {
        if (snt(i))
            dem=dem+i;
    }
    cout<<dem<<endl;
    if (snt(dem))
        cout<<"YES";
    else
        cout<<"NO";
}
