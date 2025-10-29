#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main()
{
    ifstream infile("SD.INP");
    ofstream outfile("SD.OUT");
    long long n,sum=0;
    infile>>n;
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
    outfile<<sum;
    infile.close();
    outfile.close();
    return 0;
}
