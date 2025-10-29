#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,count=0,k;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>k;
     for (int i=0;i<n;i++)
    {
        if(a[i]==k)
        count++;
    }
    cout<<count;
    return 0;
}
