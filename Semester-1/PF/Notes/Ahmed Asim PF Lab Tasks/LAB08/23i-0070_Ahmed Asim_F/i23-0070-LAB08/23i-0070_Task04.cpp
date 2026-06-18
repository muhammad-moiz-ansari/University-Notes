#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n\n";
int ran, i=1, n;
srand(static_cast<unsigned int>(time(nullptr)));
ran = 1 + rand() % 100;
cout<<"\e[3mHi! I'm thinking of a random Number between 1 and 100.\e[0m\n";
while (i<=10){
	cout<<"\e[3m--- Attempt "<<i<<" \e[0m\n";
	cout<<"Guess what number I am thinking of : ";
	cin>> n;
	if (n>ran) cout<<"\e[5mToo high.\e[0m\n";
	else if (n<ran) cout<<"\e[5mToo low.\e[0m\n";
	else{
		cout<<"\n\e[7mCONGRATULATIONS!!, You WON\e[0m\n";
		return 0;
	}
	i += 1;
}
cout<<"\n\e[7mAw! you ran out of tries. The number was "<<ran<<".\e[0m\n";
return 0;
}
