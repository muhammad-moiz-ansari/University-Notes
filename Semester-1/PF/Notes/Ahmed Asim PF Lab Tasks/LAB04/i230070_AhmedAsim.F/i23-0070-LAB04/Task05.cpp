#include <iostream>
#include <cmath>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F"<<endl;
int num; //num = Number
cout<<"Enter a four-digit number: ";
cin>>num;
int fd = ((num/1000)%10); //fd = First Digit
int ld = num%10; //ld = Last Digit
int sum = fd + ld;
cout<<"Sum of first and last digit is "<<sum<<"."<<endl;
return 0;
}
