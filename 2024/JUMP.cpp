#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define endl "\n"
using namespace std;
ll n,k,a[1000068],dem=0;
int main()
{
    skibidi;
    file("JUMP")
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<=r)
    {
        if (a[l]+a[r]>k)
        {
            dem++;
            r--;
        }
        else
        {
            dem++;
            r--;
            l++;
        }
    }
    cout<<dem;
}
/*
5 10
4 5 6 6 6
*/
