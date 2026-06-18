#include <iostream>
using namespace std;

double Calculate_Vol(double s){return (s*s*s);}
double Calculate_Vol(double l, double w, double h){return l*w*h;}
double Calculate_Vol(double r, double h){const float pi=3.14159; return (pi*r*r*h);}

int main(){
int st;
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";
cout<<"Which shape Volume do you want\n\e[2mFor Cube enter '1'\nFor Cuboid enter '2'\nFor Cylinder enter '3'\n\e[0mYour Input: ";
cin>>st;
float s,l,w,h,r;
switch (st){
case 1: 
	cout<<"\nEnter Side Lenght: ";
	cin>>s;
	cout<<"Volume of Cube with side lenght "<<s<<" is "<<Calculate_Vol(s)<<endl;
	break;
case 2:
	cout<<"\nEnter Lenght: ";
	cin>>l;
	cout<<"Enter Width: ";
	cin>>w;
	cout<<"Enter Height: ";
	cin>>h;
	cout<<"Volume of Cubiod with dimension "<<l<<"x"<<w<<"x"<<h<<" is "<<Calculate_Vol(l,w,h)<<endl;
	break;
case 3:
	cout<<"\nEnter Radius: ";
	cin>>r;
	cout<<"Enter Height: ";
	cin>>h;
	cout<<"Volume of Cylinder with radius "<<r<<" and height "<<h<<" is "<<Calculate_Vol(r,h)<<endl;
	break;
default :
	cout<<"Invalid Input; Execution Stoped\n";
}
}
