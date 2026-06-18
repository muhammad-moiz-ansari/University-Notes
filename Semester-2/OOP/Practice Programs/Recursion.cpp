#include <iostream>
using namespace std;

void parenthsize(string str, int n)
{
	if (n>0)
	{
		cout << "(";

		if (n > 1)
			parenthsize(str, --n);
		else
			cout << str;
		cout << ")";
	}
}

//int main()
//{
//	parenthsize("Hello", 5);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
bool isbalancedparentheses(char* s, int length, int open_count = 0) {
	if (open_count < 0) {
		return false;
	}
	if (length == 0) {
		return open_count == 0; // open_count == length
	}
	if (*s == '(') { // s[0] == ‘(’
		return isbalancedparentheses(s + 1, length - 1, open_count + 1);
	}
	else if (*s == ')') { // s[0] == ‘)’
		return isbalancedparentheses(s + 1, length - 1, open_count - 1);
	}
	else {
		return isbalancedparentheses(s + 1, length - 1, open_count);
	}
}

//int main()
//{
//	char s[] = "()()"; // Example string to check
//	int length = sizeof(s) - 1; // Get the length of the string
//	if (isbalancedparentheses(s, length)) {
//		cout << "The string is balanced." << endl;
//	}
//	else {
//		cout << "The string is not balanced." << endl;
//	}
//	return 0;
//}




#include <iostream>

bool oddFivesInOctalHelper(int n, int count) {
	// Base case: if n is 0, return whether count of '5's is odd
	if (n == 0) {
		return count % 2 == 1;
	}

	// Check the last digit in the octal representation
	int lastDigit = n % 8;
	if (lastDigit == 5) {
		count++;
	}

	// Recursive call with the rest of the digits and the updated count
	return oddFivesInOctalHelper(n / 8, count);
}

bool oddFivesInOctal(int n) {
	return oddFivesInOctalHelper(n, 0);
}

//int main() 
//{
//	std::cout << std::boolalpha; // To print bool values as true/false
//
//	// Test cases
//	std::cout << "oddFivesInOctal(45) = " << oddFivesInOctal(45) << std::endl; // false
//	std::cout << "oddFivesInOctal(46) = " << oddFivesInOctal(46) << std::endl; // true
//	std::cout << "oddFivesInOctal(2605) = " << oddFivesInOctal(2605) << std::endl; // true
//
//	return 0;
//}



////////////////////////////////////////////

#include <iostream>
using namespace std;

int shape(int count)
{
	cout << count << endl;
	if (count < 5)
		shape(shape(++count));

	return count;

}

//int main()
//{
//	cout << shape(3);
//	return 0;
//}


