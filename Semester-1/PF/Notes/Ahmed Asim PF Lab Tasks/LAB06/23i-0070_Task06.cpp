#include <iostream>
using namespace std;

int main(){
int p1,p2;
cout<<"Ahmed Asim || 23i-0070"<<endl;
cout<<"First Player : ";
cin>>p1;
cout<<"Second Player : ";
cin>>p2;
switch (p1){
case 1:
 switch (p2){
 case 1: cout<<"Tie"; break;
 case 2: cout<<"2nd Player wins"; break;
 case 3: cout<<"1st Player wins"; break;
 default: cout<<"Invalid Input";
 }
break;
case 2:
 switch (p2){
 case 2: cout<<"Tie"; break;
 case 3: cout<<"2nd Player wins"; break;
 case 1: cout<<"1st Player wins"; break;
 default: cout<<"Invalid Input";
 }
break;
case 3:
 switch (p2){
 case 3: cout<<"Tie"; break;
 case 1: cout<<"2nd Player wins"; break;
 case 2: cout<<"1st Player wins"; break;
 default: cout<<"Invalid Input";
 }
break;
default:
cout<<"Invalid Input";
}
cout<<endl;
return 0;
}
