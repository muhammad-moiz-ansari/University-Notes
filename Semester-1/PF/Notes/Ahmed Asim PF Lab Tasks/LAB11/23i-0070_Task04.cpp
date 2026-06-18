#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";

float array[10],total=0.0;
cout<<"Enter 10 Floating-point Number (one at a time) :-\n";
for (int x =0; x<=9; ++x){
	cout<<"Input Number "<<x+1<<" : ";
	cin>>array[x];
}
for (int x = 0; x<=9; ++x){
	total += array[x];
}
cout<<"Average of the entered number is : "<<(total/10)<<endl;
return 0;
}
