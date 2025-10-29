#include<bits/stdc++.h>
#include<fstream>
using namespace std;
bool nguyento (long long n)
{
    for (long long i=2; i<=sqrt(n);i++)
    {
        if (n%i==0)
            return false;
    }
    if (n==2||n==3)
        return true;
    if (n==1)
        return false;
    return true;
}

int main()
{
    ifstream infile("CPRIME.INP");
    ofstream outfile("CPRIME.OUT");
    long long n,cnt=0;
    infile>>n;
    for (long long i=1; i<=n; i++)
    {

        if (nguyento(i))
            cnt+=1;
    }
    outfile<<cnt;
    infile.close();
    outfile.close();
    return 0;
}
