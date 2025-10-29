#include <bits/stdc++.h>
using namespace std;
long long a,b,h,dem=0,ngay=0,luu;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>h;
    if (a<b)
    {
        cout<<-1;
        return 0;
    }
    if (a>=h)
    {
        cout<<1;
        return 0;
    }
    if (a==b)
    {
        cout<<-1;
        return 0;
    }
    luu=a-b;
    h=h-a;
    if (h%luu==0)
        ngay=h/luu;
    else
        ngay=h/luu+1;
    ngay++;
    cout<<ngay;
}
