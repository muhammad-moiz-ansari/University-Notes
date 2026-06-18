#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";
int floors,i=1,room=0,roomo=0,temp, roome=0;
cout<<"Enter number of floors : ";
cin>>floors;
while (i<=floors){
	cout<<"Enter the number of rooms on floor "<<i<<" : ";
	cin>>temp;
	room += temp;
	cout<<"How many rooms are occupied? : ";
	cin>>temp;
	roomo += temp;
	i++;
}
cout<<"The Hotel has total of "<<floors<<" floors.\n";
cout<<"The Hotel has total of "<<room<<" rooms.\n";
cout<<"There are "<<roomo<<" occupied.\n";
cout<<"There are "<<(room-roomo)<<" empty.\n";
cout<<"Percentage of occupied room is "<<((double(roomo)/room)*100)<<"%.\n";
return 0;
}
