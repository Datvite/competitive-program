#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    freopen("PARITY.INP","r",stdin);
    freopen("PARITY.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int dem=0,luu=0,h;
    int sc[1000000],sl[1000000],sh[3000000];
    sc[0]=0;
    sl[0]=0;
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
}
