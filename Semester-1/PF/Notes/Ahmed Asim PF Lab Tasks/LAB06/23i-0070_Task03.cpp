#include <iostream>
using namespace std;

int main(){
int num;
cout<<"Ahmed Asim || 23i-0070"<<endl;
cout<<"Enter Number : ";
cin>>num;
if (num>0){
  if (num%2==0) cout<<"Positive and Even"<<endl;
  else cout<<"Positive and Odd"<<endl;
}
else if (num<0){
  if (num%2==0) cout<<"Negative and Even"<<endl;
  else cout<<"Negative and Odd"<<endl;
  }
else cout<<"Zero"<<endl;
return 0;
}
