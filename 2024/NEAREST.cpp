#include<bits/stdc++.h>
using namespace std;
long nguyento (long long n)
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
    freopen("NEAREST.INP","r",stdin);
    freopen("NEAREST.OUT","w",stdout);
    int a;
    cin >> a;
    int b1 = a;
    int b2 = a;
    while (true) {
        if (nguyento(b1)) {
            cout << b1;
            break;
        }
        if (nguyento(b2)) {
            cout << b2;
            break;
        }
        b1--;
        b2++;
    }
}
