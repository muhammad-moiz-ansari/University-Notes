#include <iostream>
using namespace std;

int main(){
int age;
cout<<"Ahmed Asim || 23i-0070"<<endl;
cout<<"Enter Age : ";
cin>>age;
if (age>130) cout<<"Invald Age";
else if (age>=65&&age<=130) cout<<"$15";
else if (age>=13&&age<65) cout<<"$20";
else if (age>0&&age<13) cout<<"$10";
else if (age<=0) cout<<"Invald Age";
cout<<endl;
return 0;
}
