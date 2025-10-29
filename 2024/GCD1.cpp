#include<bits/stdc++.h>
#include<fstream>
using namespace std;
long long tonguoc(long long a,long long b,long long sum=0)
{
    for (long long i=1;i<=sqrt(a)&&i<=sqrt(b);i++)
    {
        if (a%i==0&&b%i==0)
        {
            sum+=1;
            if ((a/i)%i==0&&(b/i)%i==0)
                sum+=1;
            if (a/i==i||b/i==i)
                sum-=1;
        }
    }
    return sum;
}
int main()
{
    ifstream infile("GCD1.INP");
    ofstream outfile("GCD1.OUT");
    long long a,b;
    cin>>a>>b;
    cout<<tonguoc(a,b);
    infile.close();
    outfile.close();
    return 0;
}
