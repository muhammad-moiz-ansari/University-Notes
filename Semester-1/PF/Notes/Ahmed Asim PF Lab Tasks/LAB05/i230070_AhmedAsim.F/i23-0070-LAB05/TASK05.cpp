//Ahmed Asim, 23i-0070, BSCS-F
#include <iostream>
using namespace std;

int main() 
{
unsigned int n;
cout<<"Enter an integer: ";
cin>>n;
unsigned int even = n & 170;
unsigned int old = n & 85; 
cout<<"After swapping adjacent bits = "<<((even>>1)|(old<<1))<<endl;
return 0;
}
