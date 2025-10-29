#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long m,n,k,x,y;
    cin>>m>>n>>k;
    if (m>n)
        swap(m,n);
    if (k/2>m-1)
        m=m-1;
    else
        m=k/2;
    if (k-m>n-1)
        n=n-1;
    else
        n=k-m;
    cout<<(n+1)*(m+1);
}
