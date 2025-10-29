#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double s=0;
    cout<<fixed<<setprecision(3);
    for (int i=1;i<=n*2;i++)
    {
        if (i%2!=0)
            s=s+1.0/i;
    }
    cout<<s;
    return 0;
}
