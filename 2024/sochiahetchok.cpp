#include <bits/stdc++.h>
using namespace std;
long long n,m,k,dem=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    if (n%k!=0)
        n=n+(k-n%k);
    while (n<=m)
        {
            n=n+k;
            dem++;
        }
    cout<<dem;
}
