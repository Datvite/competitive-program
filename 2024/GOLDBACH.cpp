#include <bits/stdc++.h>
using namespace std;
long long a,b,ans,maxn=LLONG_MAX,z,i,maxn1=LLONG_MIN,n;
map<long long, int> da;
map<long long, int> db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin>>n;
    for (int aa=1;aa<=n;++aa)
    {
        cin>>a>>b;
        for (int j=2; j<=a; j++)
        {
            z=j;
            i=2;
            while (i<z)
            {
                if (z%i==0)
                {
                    z=z/i;
                    da[i]++;
                    maxn1=max(i,maxn1);
                }
                i++;
            }
            if (z!=1)
            {
                da[z]++;
                maxn1=max(z,maxn1);
            }
        }
        i=2;
        while (i<b)
        {
            if (b%i==0)
            {
                b=b/i;
                db[i]++;
                maxn1=max(i,maxn1);
            }
            i++;
        }
        if (b!=1)
        {
            db[b]++;
            maxn1=max(b,maxn1);
        }
        for (long long j=2; j<=maxn1; j++)
        {
            if (db[j]!=0)
            {
                ans=da[j]/db[j];
                if (ans<maxn)
                {
                    maxn=ans;
                }
            }

        }
        cout<<ans<<endl;
    }
}
