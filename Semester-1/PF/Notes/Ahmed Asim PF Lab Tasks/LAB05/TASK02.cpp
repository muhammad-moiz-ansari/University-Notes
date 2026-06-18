#include <iostream>
using namespace std;

int main() 
{
int n;
cout<<"Enter a number: ";
cin>>n;
cout<<n<<" % 8 = "<<(n&7)<<endl;
return 0;
}
