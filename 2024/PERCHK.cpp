#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("PERCHK.INP","r",stdin);
    freopen("PERCHK.OUT","w",stdout);
    int n;
    long long a[3000000],b[3000000];
    cin>>n;
    for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[a[i]]++;
        }
    sort (a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        if (a[i]!=i)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
