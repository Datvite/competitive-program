#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a1,a2,b1,b2,c1,c2,x=0,y=0,m,n,k;
    cin>>k;
    while (k--)
    {
        cin>>a1>>b1>>c1;
        cin>>a2>>b2>>c2;
        if (a1%a2==0||a2%a1==0)
        {
            if (a1%a2==0)
                {
                    k=a1/a2;
                    a2=a2*k;
                    b2=b2*k;
                    c2=c2*k;
                    b1=b1-b2;
                    c1=c1-c2;
                }
            else if (a2%a1==0)
                {
                    k=a2/a1;
                    a1=a1*k;
                    b1=b1*k;
                    c1=c1*k;
                    b2=b2-b1;
                    c2=c2-c1;
                }
        }
    }
}
