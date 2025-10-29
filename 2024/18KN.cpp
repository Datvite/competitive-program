#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],k,luu,dem=0,M[2000068];
void sub2()
{
    for (int i=0;i<=2000000;i++)
        {
            dem=dem+M[i];
            if (dem>=k)
                {
                    luu=i-1000000;
                    break;
                }
        }
        cout<<luu;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("18KN.INP","r",stdin);
    freopen("18KN.OUT","w",stdout);
    cin>>n>>k;
    if (k>n)
        {
            cout<<"NO";
            return 0;
        }
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        M[a[i]+1000000]++;
    }
    sub2();
}
