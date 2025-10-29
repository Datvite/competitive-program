#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    double tb=0;
    cin>>n>>k;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int maxvalua=a[0];
    for (int i=0;i<n;i++)
    {
        if (maxvalua<a[i])
            maxvalua=a[i];
    }
    cout<<maxvalua<<endl;
    int minvalua=a[1];
    for (int i=0;i<n;i++)
    {
        if (minvalua>a[i])
            minvalua=a[i];
    }
    cout<<minvalua<<endl;
    int maxvalua1;
    for (int i=0;i<n;i++)
    {
        if (a[i]<0)
            {
                maxvalua1=a[i];
            }
    }
    for (int i=0;i<n;i++)
    {
        if (maxvalua1<a[i]&&a[i]<0)
            maxvalua1=a[i];
    }
    cout<<maxvalua1<<endl;
    int maxvalua2;
    for (int i=0;i<n;i++)
    {
        if (a[i]>0)
            {
                maxvalua2=a[i];
            }
    }
    for (int i=0;i<n;i++)
    {
        if (maxvalua2>a[i]&&a[i]>0)
            maxvalua2=a[i];
    }
    cout<<maxvalua2<<endl;
    int maxvalua3;
    for (int i=0;i<n;i++)
    {
        if (a[i]%2==0)
            maxvalua3=a[i];
    }
    for (int i=0;i<n;i++)
    {
        if (maxvalua3<a[i]&&a[i]%2==0)
            maxvalua3=a[i];
    }
    cout<<maxvalua3<<endl;
    int maxvalua4=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]>0)
            {
                maxvalua4=a[i];
            }
    }
    for (int i=0;i<n;i++)
    {
        if (maxvalua4>a[i]&&a[i]>0&&a[i]%2!=0)
            maxvalua4=a[i];
    }
    cout<<maxvalua4<<endl;
    int count=0;
    for (int i=0;i<n;i++)
    {
        if (maxvalua==a[i])
            count++;
    }
    cout<<count<<endl;
    int count1=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]==k)
            count1++;
    }
    cout<<count1<<endl;
    int count2=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]==k)
        {
            count2=i+1;
            break;

        }
    }
    cout<<count2<<endl;
    int count3=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]%k==0&&a[i]>0)
        {
            count3++;
        }
    }
    cout<<count3;
}
