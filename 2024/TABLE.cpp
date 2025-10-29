#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long n;
    int j=0;
    int i=0;
    cin>>n;
    for(int k=1;k<=n;k++)
    {
        {
        j++;
        if(i*j>=n)
            {
            cout<<i<<" "<<j;
            return 0;
            }
        i++;
        if(i*j>=n)
            {
            cout<<i<<" "<<j;
            return 0;
            }

        }
    }
}
