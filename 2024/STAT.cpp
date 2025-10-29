#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("STAT.INP","r",stdin);
    //freopen("STAT.OUT","w",stdout);
    int n;
    cin>>n;
    int a[1000000],b[1000000];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    for (int i=0; i<n; i++)
    {
        cout<<lower_bound(a, a + n, b[i])-a<<" "<<n-(upper_bound(a, a + n, b[i])-a)<<endl;
    }
}
