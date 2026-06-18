#include <iostream>
using namespace std;

void swap_pointers(int* p,int* q);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int a, b;
cout<<"Enter a : ";cin>>a;
cout<<"Enter b : ";cin>>b;
int* p = &a;
int* q = &b;
cout<<"\nValue of a is : "<<a<<endl;
cout<<"Value of b is : "<<b<<endl;
swap_pointers(p,q);
cout<<"\nNew value of a after swap is : "<<a<<endl;
cout<<"New value of b after swap is : "<<b<<endl;
return 0;
}

void swap_pointers(int* p,int* q) {
*p = *p^*q;
*q = *p^*q;
*p = *p^*q;
}
