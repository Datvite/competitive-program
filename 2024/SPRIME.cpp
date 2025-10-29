#include<bits/stdc++.h>
using namespace std;
bool nguyento (long long n)
{
    if (n<2)
        return false;
    for (long long i=2; i<=sqrt(n);i++)
    {
        if (n%i==0)
            return false;
    }
    return true;
}
int main()
{
    freopen("SPRIME.INP","r",stdin);
    freopen("SPRIME.OUT","w",stdout);
    long long n,tong=0;
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        if (nguyento(i))
            tong+=i;
    }
    cout<<tong<<endl;
    if (nguyento(tong))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
