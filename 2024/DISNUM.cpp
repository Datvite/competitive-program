#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("DISNUM.INP","r",stdin);
    freopen("DISNUM.OUT","w",stdout);
    long long n,a[300000];
    map<long long,int>M;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        M[a[i]]++;
    }
    cout<<M.size();
}
