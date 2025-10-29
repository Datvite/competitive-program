#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main()
{
    ifstream infile("GCD.INP");
    ofstream outfile("GCD.OUT");
    long long a,b;
    infile>>a>>b;
    long long t=__gcd(a,b);
    outfile<<t;
    infile.close();
    outfile.close();
    return 0;
}

