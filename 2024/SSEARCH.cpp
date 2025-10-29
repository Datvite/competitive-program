#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("SSEARCH.INP","r",stdin);
    freopen("SSEARCH.OUT","w",stdout);
    long long n,x,s=0;
    cin>>n;
    long long a[3000009];
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    cin>>x;
    for (int i=0;i<n;i++)
    {
        if (a[i]>=x)
            {
                s=i+1;
                break;
            }
    }
    if (s!=0)
        cout<<s<<endl;
    else
        cout<<-1<<endl;
    s=0;
    for (int i=0;i<n;i++)
    {
            if (a[i]<x)
            {
                s=i+1;
            }
    }
    if (s!=0)
        cout<<s;
    else
        cout<<-1;
}
