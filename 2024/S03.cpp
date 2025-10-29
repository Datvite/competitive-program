#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("S03.INP","r",stdin);
    freopen("S03.OUT","w",stdout);
    int n,m,t;
    cin>>n>>m;
    int a[1000000];
    int coun=0;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=0; i<m; i++)
    {
        cin>>t;
        if (upper_bound(a, a + n, t) - lower_bound(a, a + n, t)!=0)
            cout<<upper_bound(a, a + n, t) - lower_bound(a, a + n, t)<<endl;
        else
            cout<<"NO"<<endl;
    }
}
