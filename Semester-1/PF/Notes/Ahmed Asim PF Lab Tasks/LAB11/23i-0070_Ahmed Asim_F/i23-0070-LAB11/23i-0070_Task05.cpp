#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";

int array[5];
cout<<"Enter 5 Integers (one at a time) :-\n";
for (int x =1; x<=5; ++x){
	cout<<"Input Integer "<<x<<" : ";
	cin>>array[x];
}
int low = array[1], high = array[1];
for (int x = 2; x<=5; ++x){
	if (array[x]>high) high=array[x];
	if (array[x]<low) low=array[x];
}
cout<<"Largest number in array is : "<<high<<endl;
cout<<"Smallest number in array is : "<<low<<endl;
return 0;
}
