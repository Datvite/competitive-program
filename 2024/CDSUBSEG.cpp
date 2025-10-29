#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],b,k;
long long dodai(long long a[],long long b)
{
    long long uochientai=0;
    long long maxn=0;
    long long batdau=0;
    for (int i=0;i<b;i++)
        {
            if (uochientai==0)
                uochientai=a[i];
            else
                uochientai=__gcd(uochientai,a[i]);
            while (uochientai==1&&batdau<=i)
                {
                    uochientai=a[batdau];
                    batdau++;
                    for (int j=batdau;j<=i;j++)
                        {
                            uochientai=__gcd(uochientai,a[j]);

                        }
                }
                if (uochientai>1)
                    maxn=max(maxn,i-batdau+1);
        }
    return maxn;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>b;
        for (int j=0; j<b; j++)
            cin>>a[j];
        k=dodai(a,b);
        if (k<=1)
            cout<<0;
        else
            cout<<k<<endl;
    }
}
