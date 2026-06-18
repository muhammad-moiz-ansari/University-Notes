#include <iostream>
using namespace std;

void add_arr(int* p,int* sum_ptr, int size);

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int size;
cout<<"Enter the lenght of array : ";
cin>>size;
int arr[size];
int* p = arr;
for (int i=0;i<size;i++) {
	cout<<i+1<<" : ";
	cin>>*(p+i);
}
int sum=0;
int* sum_ptr = &sum;
add_arr(p,sum_ptr,size);
cout<<"Sum of array is : "<<sum<<endl;
return 0;
}

void add_arr(int* p,int* sum_ptr, int size){
for (int i=0;i<size;i++) {*sum_ptr=*sum_ptr+*(p+i);}	
}





