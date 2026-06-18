#include <iostream>
#include <ctime>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
const int size = 20;
int i;
bool p=true;
char arr[size]={'\0'};
cout<<"Enter Array : ";
cin>>arr;
for(i=0;i<size;i++) if (arr[i]=='\0') break;
for(int j=0;j<=i;++j,--i) if(arr[i-1]!=arr[j]) p=false;
if (p==1) cout<<"The entered character array is a palindrome\n";
else cout<<"The entered character array is not a palindrome\n";
return 0;
}
