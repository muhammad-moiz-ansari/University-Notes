#include <iostream>
using namespace std;

int main(){
double per;
cout<<"Ahmed Asim || 23i-0070"<<endl;
cout<<"Enter Percentage : ";
cin>>per;
if (per>=90) cout<<"Grade A";
else if (per>=80&&per<90) cout<<"Grade B";
else if (per>=70&&per<80) cout<<"Grade C";
else if (per<70) cout<<"Grade D";
cout<<endl;
return 0;
}
