#include<bits/stdc++.h>
using namespace std;
long long n,dem=0,s;
bool check (long long n)
{
    if (n==1)
        return true;
    for (int i=2;i<=sqrt(n);i++)
        {
            if (n%i==0)
            return true;
        }
    return false;
}
void sub1()
{
    s=sqrt(n);
    for (int i=1; i<=s; i++)
    {
        if (n%i==0)
        {
            if (check(i)&&check(n/i))
            {
                dem=dem+2;
            }
            else
            {
                if (check(i)||check(n/i))
                {
                    dem=dem+1;
                }
            }
        }
    }
    cout<<dem;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("NPRI11.INP","r",stdin);
    freopen("NPRI11.OUT","w",stdout);
    cin>>n;
    if (n>0)
    sub1();
}
