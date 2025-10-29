#include<bits/stdc++.h>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
    ifstream infile("DIGITSUM.INP");
    ofstream outfile("DIGITSUM.OUT");
    long long n,sum=0;
    infile>>n;
    while (n!=0)
    {
        sum+=n%10;
        n=n/10;
    }
    outfile<<sum;
    infile.close();
    outfile.close();
    return 0;
}
