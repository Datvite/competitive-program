#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,m,maxidol=0;
    cin>>n;
    int a[3000009],b[3000009];
    for (int i=1;i<=n;i++)
    {
        cin>>k;
        for (int j=1;j<=k;j++)
        {
            cin>>m;
            b[m]++;
            maxidol=max(maxidol,b[m]);
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (b[i]==maxidol)
            cout<<i<<" ";
    }
}
