#include <iostream>
#include <ctime>
using namespace std;

bool flip();
void coin_tossing(int n);

int main(){
int n;
cout<<"Ahmed Asim | 23i-0070 | BSCS(F)\n";
srand(static_cast<unsigned int>(time(nullptr)));
cout<<"Enter the number of times you want to flip coin: ";
cin>>n;
coin_tossing(n);
return 0;
}

bool flip() {return (0 + rand() % 2);}

void coin_tossing(int n){
bool turn;
int heads=0, tails=0;
for (int i = 0; i<=(n-1); ++i){
	turn = flip();
	if (turn==0) tails+=1;
	else if (turn==1) heads+=1;
	else cout<<"error";
}
cout<<"Result after "<<n<<" coin toss:- \n Heads : "<<heads<<"\n Tails : "<<tails<<endl;
}
