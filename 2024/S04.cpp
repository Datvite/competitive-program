#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("S04.INP","r",stdin);
    freopen("S04.OUT","w",stdout);
    int n,m,t,s;
    cin>>n>>m;
    int a[1000000];
    for (int i=0;i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=0;i<m; i++)
    {
        cin>>t>>s;
        cout<<upper_bound(a,a+n,s)-lower_bound(a,a+n,t)<<endl;
    }
}
