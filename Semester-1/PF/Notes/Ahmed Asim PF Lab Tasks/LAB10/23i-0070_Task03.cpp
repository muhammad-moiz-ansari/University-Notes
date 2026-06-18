#include <iostream>
#include <ctime>
using namespace std;

int main(){
int i,n,cn,scorec=0,scoren=0;
char input;
bool done=false,win;
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";
cout<<"\e[1mWelcome To Odds & Evens\n\n";
srand(static_cast<unsigned int>(time(nullptr)));
do {
	cn = (1 + rand() % 10);
	cout<<"\e[1m\e[2mTo Play Game Enter A Number Between 1 & 10 \nTo Exit The Enter Anything Else\n\e[0m\e[3mYour Input : ";
	i=1;
	while(done==false){
		input = cin.get();  
		if (input =='\n'&&i>1) break; 
		if (!(input>='0'&&input<='9')) n=-1;
		else if (input!='0'&&i>1) n=-1;
		else if (input=='0'&&i==1) n=-1;
		else if(input>='0'&&input<='9') {
			if (input=='0') n=10;
			else n = input - '0';
		} 
		i+=1;
	}
	cout<<"\e[0m";
	if (n>=1&&n<=10){
		cout<<"\n";
		if ((n+cn)%2==0){
		win=1;
		scorec+=1;
		}
		else {
		win=0;
		scoren+=1;
		}
		cout<<"Computer Number was "<<cn<<"\nYour Number was "<<n<<"\n\e[0mThus, \e[1m"<<(win==0?"YOU\e[0m are":"COMPUTER\e[0m is")<<" the winner of this round.\e[0m\n\n";
	}
	else cout<<"\e[1mExiting Game...\n\n\e[0mResults:\n\e[1m\e[7mCOMPUTER has won "<<scorec<<" times\n  YOU have won "<<scoren<<" times  \e[0m\n";		
} while (n>=1&&n<=10);

return 0;
}
