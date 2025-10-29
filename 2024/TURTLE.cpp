#include<bits/stdc++.h>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
    ifstream infile("TURTLE.INP");
    ofstream outfile("TURTLE.OUT");
    long long a[4],min1,max2;
    for (int i=0; i<4; i++)
    {
        infile>>a[i];
    }
    min1=min({a[0], a[1], a[2], a[3]});
    sort (begin(a),end(a),greater<long long>());
    outfile<<min1*a[1];
    infile.close();
    outfile.close();
    return 0;
}
