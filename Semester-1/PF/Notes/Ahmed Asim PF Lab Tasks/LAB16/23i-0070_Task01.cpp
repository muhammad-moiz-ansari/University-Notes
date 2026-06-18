#include <iostream>
#include <fstream>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int count=0;
char temp;
string sentence = "Time is a great teacher but unfortunately it kills all its pupils. Berlioz";
fstream file_var;
file_var.open("OUT.txt");//,iso::out);
if (!file_var) {
	cout<<"Error, file not found";
}
else {
	file_var << sentence;
}
file_var.close();
file_var.open("OUT.txt");//,iso::in);
if (!file_var) {
	cout<<"Error, file not found";
}
else {
	while (1){
		file_var>>temp;
		if (temp>='A'&&temp<='Z'||temp>='a'&&temp<='z')count++;
		if (file_var.eof()) break;
	}
}
file_var.close();
cout<<"Number of alphabet in sentence are : "<<count<<endl;
return 0;
}

