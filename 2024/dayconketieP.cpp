#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1000068],i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1; i<=k; i++)
        cin>>a[i];
    i=k;
    while (i>0)
    {
        if (a[i]<n-k+i)
        {
            a[i]++;
            for (int j=i+1; j<=k; j++)
            {
                a[j]=a[j-1]+1;
            }
            break;
        }
        i--;
    }
    if (i==0)
        cout<<"NOTAVAILABLE";
    else
        for (int j=1; j<=k; j++)
            cout<<a[j]<<" ";
}
