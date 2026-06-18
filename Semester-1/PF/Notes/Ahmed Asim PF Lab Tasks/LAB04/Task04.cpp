#include <iostream>
#include <cmath>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F"<<endl;
int a,b,c;
cout<<"Enter coefficient a: ";
cin>>a;
cout<<"Enter coefficient b: ";
cin>>b;
cout<<"Enter coefficient c: ";
cin>>c;
cout<<"Roots are:-\nx1 = "<<(((-b)+sqrt((b*b)-(4*a*c)))/(2*a))<<"\nx2 = "<<(((-b)-sqrt((b*b)-(4*a*c)))/(2*a))<<endl;
return 0;
}
