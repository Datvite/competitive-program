#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<fixed<<setprecision(3);
    long long tong=0;
    double s=0;
    for (int i=1;i<=n;i++)
        {
         s+=1.0/(tong+i);
         tong=tong+i;
        }
    cout<<s;
    return 0;

    }
