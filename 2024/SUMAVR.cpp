#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[1000000];
    long long t=0,s=0;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        t=a[i]*i;s=t;
        cout<<t-s<<" ";

    }
}



