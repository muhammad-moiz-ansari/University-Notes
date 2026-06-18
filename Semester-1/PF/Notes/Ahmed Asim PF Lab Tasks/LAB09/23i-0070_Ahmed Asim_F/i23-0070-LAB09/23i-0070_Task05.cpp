#include <iostream>
using namespace std;

int main(){
cout<<"Ahmed Asim / 23i-0070 / BSCS-F"<<endl;
int n,t,t2,sum,sumtotal=0; //t = temp
cout<<"Enter a Number : ";
cin>>n;
n *= 10;
while(int(n/10)!=0){
	n = n/10;
  t = n%10;
  t2 = 1;
  sum = 1;
  while(t2<=t){
  	sum *= t;
  	t2 += 1;
  }
  sumtotal+=sum;
}
cout<<"Answer = "<<sumtotal<<endl;
return 0;
}
