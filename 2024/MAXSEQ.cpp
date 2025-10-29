#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long A[1000008];
    for (int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int maxvalua=A[0];
    for (int i=0;i<n;i++)
    {
        if (A[i]>maxvalua)
            maxvalua=A[i];
    }
    cout<<maxvalua;
    return 0;
}
