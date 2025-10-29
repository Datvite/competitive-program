#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
long long n,b,d,a,c;
__int128_t ad,cb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++)
        {
            cin>>a>>b>>c>>d;
            if (b<0)
                {
                    a=-a;
                    b=-b;
                }
            if (d<0)
                {
                    c=-c;
                    d=-d;
                }
            ad=a*d;
            cb=c*b;
            if (ad>cb)
                cout<<1<<endl;
            if (ad==cb)
                cout<<0<<endl;
            if (ad<cb)
                cout<<-1<<endl;
        }
}
