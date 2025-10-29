#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("S01.INP","r",stdin);
    freopen("S01.OUT","w",stdout);
    int n,m,t;
    cin>>n>>m;
    int a[1000000];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=0;i<m;i++)
    {
        cin>>t;
        if (binary_search(a,a+n,t))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
