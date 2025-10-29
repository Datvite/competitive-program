#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,sum=0,sum1=0,sum2=0,sole=0,duong=0,sumam=0,sumchanduong=0;
    long double tb=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;i++)
    {
        if (a[i]>0)
           cout<<i+1<<" ";
    }
    cout<<endl;
    cout<<a[n-1]-a[0]<<endl;
    for (int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    cout<<sum<<endl;
    for (int i=0;i<n;i++)
    {
        sum1+=abs(a[i]);
    }
    cout<<sum1<<endl;
    for (int i=0;i<n;i++)
    {
        tb+=a[i];
    }
    cout<<fixed<<setprecision(2);
    cout<<tb/n<<endl;
    cout<<fixed<<setprecision(0);
    for (int i=0;i<n;i++)
    {
        if (i%2!=0)
            sum2+=a[i];
    }
    cout<<sum2<<endl;
    for (int i=0;i<n;i++)
    {
        if (a[i]%2!=0)
            sole+=1;
    }
    cout<<sole<<endl;
    for (int i=0;i<n;i++)
    {
        if (a[i]>0)
            duong+=1;
    }
    cout<<duong<<endl;
    for (int i=0;i<n;i++)
    {
        if (i%2==0&&a[i]<0)
            sumam+=a[i];
    }
    cout<<sumam<<endl;
    for (int i=0;i<n;i++)
    {
        if (a[i]>0&&a[i]%2==0&&(i+1)%2==0)
            sumchanduong+=a[i];
    }
    cout<<sumchanduong;
    return 0;
}
