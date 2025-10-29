#include<bits/stdc++.h>
using namespace std;
long long n,a[1000068],dem = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("14ATH.INP","r",stdin);
    freopen("14ATH.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<n; i++)
    {
        if(a[i]==a[i+1])
            dem++;
    }
    cout<<dem<<'\n';
    if(dem != 0)
        for(int i=1; i<n; i++)
        {
            if(a[i]==a[i+1])
                cout<<i<<" "<<i+1<<'\n';
        }
    return 0;
}
