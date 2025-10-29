#include <bits/stdc++.h>
using namespace std;
long long n,a,x,b,y,tong=0,tien=0,sa,sb,k,l,minn=LLONG_MAX;
int main()
{
    cin>>n>>a>>x>>b>>y;
    if (n%a==0)
        sa=n/a;
    else
        sa=n/a+1;
    l=sa;
    for (int i=1; i<=l; i++)
    {
        k=a*sa;
        if ((n-k)%b==0)
            sb=(n-k)/b;
        else
            sb=(n-k)/b+1;
        if (sb>0)
        {
            tong=sa*a+sb*b;
            tien=sa*x+sb*y;
        }
        else
        {
            tong=sa*a;
            tien=sa*x;
        }
        if (tong>=n)
            minn=min(minn,tien);
        sa--;
    }
    cout<<minn;
}
