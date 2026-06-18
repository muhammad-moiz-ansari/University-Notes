//Ahmed Asim, 23i-0070, BSCS-F
#include <iostream>
using namespace std;

int main() 
{
int y,x;
cout<<"Enter number 1: ";
cin>>x;
cout<<"Enter number 2: ";
cin>>y;
x = x ^ y;
y = y ^ x;
x = x ^ y;
cout<<"Number 1 is "<<x<<"\nNumber 2 is "<<y<<endl;
return 0;
}
