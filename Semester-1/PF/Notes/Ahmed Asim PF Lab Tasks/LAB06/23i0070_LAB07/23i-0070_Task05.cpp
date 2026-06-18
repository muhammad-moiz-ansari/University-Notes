#include <iostream>
using namespace std;

int main(){
int op1,op2;
char op;
cout<<"Ahmed Asim || 23i-0070"<<endl;
cout<<"Enter Operand1 : ";
cin>>op1;
cout<<"Enter Operand2 : ";
cin>>op2;
cout<<"Enter Operator : ";
cin>>op;
switch (op){
case '-':
 cout<<"Result = "<<(op1-op2)<<endl;
break;
case '+':
cout<<"Result = "<<(op1+op2)<<endl;
break;
case '/':
 cout<<"Result = "<<(op1/op2)<<endl;
break;
case '*':
cout<<"Result = "<<(op1*op2)<<endl;
break;
return 0;
}
}
