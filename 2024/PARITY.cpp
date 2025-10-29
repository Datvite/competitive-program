#include<bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{
    skibidi
    freopen("PARITY.INP","r",stdin);
    freopen("PARITY.OUT","w",stdout);
    long long n;
    cin>>n;
    long long dem=0,luu=0,h=0;
    long long sh[3000000],a[1000000];
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        sh[h]++;
        if (a[i]%2==0)
            h++;
        else
            h--;
        luu=luu+sh[h];
    }
    cout<<luu;
    return 0;
}
