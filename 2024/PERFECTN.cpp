#include<bits/stdc++.h>
#include<fstream>
using namespace std;
long long tonguoc (long long n,long long sum=0)
{
    for (long long i=1;i<=sqrt(n);i++)
    {
        if (n%i==0)
        {
            sum=sum+i;
            sum=sum+(n/i);
            if (i==n/i)
                sum=sum-i;
        }
    }
    return sum;
}
int main()
{
    ifstream infile("ISPER.INP");
    ofstream outfile("ISPER.OUT");
    long long n;
    infile>>n;
    for (long long i=1; i<=n; i++)
    {
        if (tonguoc(i)-i==i)
            outfile<<i<<" ";
    }
    infile.close();
    outfile.close();
    return 0;
}
