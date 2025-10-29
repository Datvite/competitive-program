#include <iostream>
using namespace std;
int main()
{
int d, m, y, c, k, dow;
cout << "Date? d m y: ";
cin >> d >> m >> y;
if (m < 3)
{
m += 12; y--;
}
c = y / 100;
k = y % 100;
dow =
d +
26 * (m + 1) / 10 +
k + k / 4 +
c / 4 + 5 * c;
cout<<dow;
switch(dow % 7)
{
case 0: cout << "Saturday"; break;
case 1: cout << "Sunday"; break;
case 2: cout << "Monday"; break;
case 3: cout << "Tuesday"; break;
case 4: cout << "Wednesday"; break;
case 5: cout << "Thursday"; break;
case 6: cout << "Friday"; break;
}
}
