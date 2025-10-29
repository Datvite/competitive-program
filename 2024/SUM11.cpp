#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long double S;
    cin >> n;
    S=1/18-1/(n+1)*(n+2)*(n+3);
    cout <<fixed<<setprecision(3);
    cout <<S;
    return 0;
}
