#include <bits/stdc++.h>
using namespace std;
long long n,m,dem=0,c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    if (n<m)
        swap(n,m);
    while (n%m!=0)
        {
           dem=dem+n/m;
           c=m;
           m=n%m;
           n=c;
        }

    dem=dem+n/m;
    cout<<dem;
}
