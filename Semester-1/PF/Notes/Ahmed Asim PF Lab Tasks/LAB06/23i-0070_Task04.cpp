#include <iostream>
using namespace std;

int main(){
int age,score;
cout<<"Ahmed Asim || 23i-0070"<<endl;
cout<<"Enter Age : ";
cin>>age;
cout<<"Enter Exam Score : ";
cin>>score;
if (age<21&&age>17){
  bool PC;
  cout<<"If Parental Consent is 'yes', Enter 1 Else Enter 0: ";
  cin>>PC;
  if ((age>=18&&age<=30)&&(score>=60)&&(PC==1)) cout<<"Eligible to enroll in the course";
  else cout<<"Not eligible to enroll in the course";
  }
  else if ((age>=18&&age<=30)&&(score>=60)) cout<<"Eligible to enroll in the course";
  else cout<<"Not eligible to enroll in the course";
  cout<<endl;
return 0;
}
