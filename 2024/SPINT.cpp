#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SPINT.INP","r",stdin);
    freopen("SPINT.OUT","w",stdout);
    int n;
    cin>>n;
    int a[1000078],maxa=1;
    for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            maxa=max(maxa,a[i]);
        }
    sort (a+1,a+n+1);
    for (int i=1;i<=maxa+1;i++)
    {
        if (binary_search(a+1,a+n+1,i)==false)
        {
            cout<<i;
            return 0;
        }
    }
}
