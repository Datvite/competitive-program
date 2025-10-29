#include <bits/stdc++.h>
using namespace std;
long long n,a,x,b,y,k,sb,minn,tong,tien,tien1,tien2,ll;
long long gg(long long n,long long a, long long x, long long b, long long y)
{
    if (n%a==0)
    {
        k=n/a;
        tien=k*x;
        tong=k*a;
        minn=tien;
    }
    else
    {
        k=n/a+1;
        tien=k*x;
        minn=tien;
        tong=k*a;
    }
    while (tong>0)
    {
        tong=tong-a;
        tien=tien-x;
        ll=n-tong;
        if (ll%b==0)
        {
            sb=ll/b;
            tien1=sb*y;
            tien2=tien+tien1;
        }
        else if (b>ll)
        {
            sb=1;
            tien1=sb*y;
            tien2=tien+tien1;
        }
        else
        {
            sb=ll/b+1;
            tien1=sb*y;
            tien2=tien+tien1;
        }
        minn=min(minn,tien2);
    }
    return minn;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>a>>x>>b>>y;
    cout<<min(gg(n,a,x,b,y),gg(n,b,y,a,x));
}
