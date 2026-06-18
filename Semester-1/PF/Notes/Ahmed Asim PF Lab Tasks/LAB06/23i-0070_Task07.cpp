#include <iostream>
using namespace std;

int main(){
double val;
char ut;
cout<<"Ahmed Asim || 23i-0070"<<endl;
cout<<"Enter Unit Type (for in to cm enter 'I' else for pount to kg enter 'P'): ";
cin>>ut;
cout<<"Enter Value : ";
cin>>val;
switch (ut){
case 'P':
 val *= 0.453592;
 cout<<"Converted Value = "<<val<<" kg";
break;
case 'I':
  val *= 2.54;
 cout<<"Converted Value = "<<val<<" cm";
break;
default :
cout<<"Invalid Input";
}
cout<<endl;
return 0;
}
