#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i=1,souoc=0;
    cin>>n;
    while (i<=n)
    {
        if (n%i==0)
            souoc++;
        i++;
    }
    cout<<souoc;
    return 0;
}
