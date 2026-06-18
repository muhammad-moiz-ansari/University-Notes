#include <iostream>
#include <fstream>
using namespace std;

int main(){
cout<<"Ahmed Asim | 23i-0070 | BSCS-F\n";
int count=0;
char temp[500];
string story = "“The rose is red.\nA girl is playing there.\nThere is a playground.\nAn aeroplane is in the sky.\nNumbers are not allowed in the password.”";
fstream file_var;
//Writing data to stroy.txt
file_var.open("story.txt");//,iso::out);
if (!file_var) {
	cout<<"Error, file not found";
}
else {
	file_var << story;
}
file_var.close();
//Reading data from stroy.txt
file_var.open("story.txt");//,iso::in);
if (!file_var) {
	cout<<"Error, file not found";
}
else {
	while (1){
		file_var>>temp[count];
		count++;
		if (file_var.eof()) break;
	}
}
file_var.close();
//Writing data to output.txt
file_var.open("output.txt");//,iso::out);
if (!file_var) {
	cout<<"Error, file not found";
}
else {
	file_var << temp;
}
file_var.close();

return 0;
}

