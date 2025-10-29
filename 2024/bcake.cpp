#include <bits/stdc++.h>
using namespace std;
float n,a[1000068],b[1000068],k,q,s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    k=a[1]*a[1]*b[1]*3.1415926;
    s=k;
    for (int i=2;i<=n;i++)
        {
            q=a[i]*a[i]*b[i]*3.14;
            if (s<q)
                k=k+q;
            s=q;
        }
    cout<<fixed<<setprecision(6);
    cout<<k;
}
