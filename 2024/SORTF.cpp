#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("SORTF.INP","r",stdin);
    freopen("SORTF.OUT","w",stdout);
    int n;
    cin>>n;
    int a[1000009];
    for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    sort(a,a+n);
    for (int i=0;i<n;i++)
        {
            if (a[i]%2==0)
                cout<<a[i]<<" ";
        }
    sort(a,a+n,greater<int>());
    for (int i=0;i<n;i++)
        {
            if (a[i]%2!=0)
                cout<<a[i]<<" ";
        }
}
