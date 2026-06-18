#include <iostream>
using namespace std;

void CtoK(float& temp);
void KtoF(float& temp);
void FtoC(float& temp);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
float temp;
cout<<"Enter Temperature in centigrade : ";
cin>>temp;
CtoK(temp); cout<<"\nTemperature in kelvin is : "<<temp;
KtoF(temp); cout<<"\nTemperature in fahrenheit is : "<<temp;
FtoC(temp); cout<<"\nTemperature in centigrade is : "<<temp;
cout<<endl;
return 0;
}

void CtoK(float& temp) {temp = (temp+273.15);}
void KtoF(float& temp) {temp=(temp-273.1595)*(9.0/5.0)+32;}
void FtoC(float& temp) {temp=(temp-32)*(5.0/9.0);}
