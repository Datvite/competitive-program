#include <bits/stdc++.h>
using namespace std;
long long n,x,m;
long long power(long long a, long long b, long long M)
{
    long long kq = 1;
    while (b > 0)
    {
        if (b % 2)
            kq = kq * a % M;
        a = a * a % M;
        b /= 2;
    }
    return kq;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin>>x>>n>>m)
        cout<<power(x,n,m)<<endl;
}
