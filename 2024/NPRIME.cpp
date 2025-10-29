#include<bits/stdc++.h>
using namespace std;
bool nguyento (long long n)
{
    if (n<2)
        return false;
    for (int i=2;i<=sqrt(n);i++)
    {
        if (n%i==0)
            return false;
    }
    return true;
}
int main()
{
    freopen("NPRIME.INP","r",stdin);
    freopen("NPRIME.OUT","w",stdout);
    long long T;
    cin>>T;
    long long t=sqrt(T);
    if (t*t<T&&nguyento(t))
        t++;
    while (true)
    {
        if (nguyento(t))
        {
            cout<<t*t;
            break;
        }
        t++;
    }

}
