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
    freopen("LPRIME.INP","r",stdin);
    freopen("LPRIME.OUT","w",stdout);
    long long n;
    cin>>n;
    long long P=n;
    while (nguyento(P)==false)
        {
            P--;
        }
    cout<<P;
    return 0;

}
