#include <bits/stdc++.h>
using namespace std;
long long n,c[1000068],a,b,s[1000068],ans,k,maxn=LLONG_MIN;
bool check=false;
void solelonnhat()
{
    s[0]=0;
    s[1]=1;
    for (int i=2; i<=1000068; i++)
    {
        if (i%2!=0)
        {
            s[i]=s[i-1]+i;
        }
        else
        {
            check=false;
            maxn=LLONG_MIN;
            for (long long j=2; j<=sqrt(i); j++)
            {
                if (i%j==0)
                {
                    k=i/j;
                    if (k%2!=0)
                    {
                        maxn=max(maxn,k);
                        check=true;
                    }
                    else if (j%2!=0)
                    {
                        maxn=max(maxn,j);
                        check=true;
                    }

                }
            }
            if (check)
                s[i]=s[i-1]+maxn;
            else
                {
                    s[i]=s[i-1]+1;
                }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    solelonnhat();
    for (int i=1; i<=n; i++)
    {
        cin>>a>>b;
        ans=s[b]-s[a-1];
        cout<<ans<<endl;
    }
}
