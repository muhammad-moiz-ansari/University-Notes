#include <iostream>
using namespace std;

int main() 
{
int y,x;
cout<<"Enter number x: ";
cin>>x;
cout<<"Enter number y: ";
cin>>y;
cout<<(((x>>31)&1)^((y>>31)&1))<<endl;
return 0;
}
