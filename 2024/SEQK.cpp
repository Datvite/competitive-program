#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("SEQK.INP","r",stdin);
    //freopen("SEQK.OUT","w",stdout);
    long long n,a[300000],j=0,k;
    map<long long,long long>M;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        M[a[i]]=i;
    }
    for (int i=1; i<=n; i++)
    {
        if (M[a[i]+k]!=0)
        {
            cout<<i<<" "<<M[a[i]+k];
            return 0;
        }
    }
    cout<<0<<" "<<0;
}
