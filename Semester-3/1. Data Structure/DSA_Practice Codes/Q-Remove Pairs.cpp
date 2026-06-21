#include <iostream>
#include <stack>
#include <string>
using namespace std;

//       not works:
//string removePairs(string input) 
//{
//	stack <char> stack1;
//	stack <char> stack2;
//	//Write code here
//	
//	for (int i = 0; i < input.size(); ++i)
//		stack1.push(input[i]);
//
//	int index = input.size() - 1, ind, sizeind;
//	bool b = 0;
//	while (!stack1.empty())
//	{
//		if (input[index] != 0)
//		{
//			b = 0;
//			sizeind = index;
//			stack2.push(stack1.top());
//			ind = index - 1;
//			for (; ind >= 0; --ind)
//			{
//				//if (input[ind] == 0)
//				//	--sizeind;
//				if(input[ind] == stack1.top())
//				{
//					stack2.pop();
//					input[ind] = 0;
//					b = 1;
//					break;
//				}
//			}
//			for (int i = ind; i < input.size(); ++i)
//			{
//				input[i] = input[i + 1];
//			}
//			stack1.pop();
//			if (b)
//			{
//				for (int i = 0; i < index - ind; ++i)
//					stack1.pop();
//				for (int i = ind; i < index; ++i)
//					//if (input[i] != 0)
//						stack1.push(input[i]);
//			}
//		}
//		--index;
//	}
//	int i = 0;
//	for (; i < input.size() && !stack2.empty(); ++i)
//	{
//		input[i] = stack2.top();
//		stack2.pop();
//	}
//	input[i++] = '\0';
//	return input.substr(0, i);
//}

string removePairs(string input)
{
	stack <char> stack1;
	stack <char> stack2;
	//Write code here

	for (int i = 0; i < input.size(); ++i)
		stack1.push(input[i]);

	int index = input.size() - 1, ind, sizeind;
	bool b = 0;
	while (!stack1.empty())
	{
		if (input[index] != 0)
		{
			b = 0;
			sizeind = index;
			stack2.push(stack1.top());
			ind = index - 1;
			for (; ind >= 0; --ind)
			{
				if (input[ind] == 0)
					--sizeind;
				else if (input[ind] == stack1.top())
				{
					stack2.pop();
					input[ind] = 0;
					b = 1;
					break;
				}
			}
			stack1.pop();
			if (b)
			{
				for (int i = 0; i < sizeind - ind; ++i)
					stack1.pop();
				for (int i = ind; i < index; ++i)
					if (input[i] != 0)
						stack1.push(input[i]);
			}
		}
		--index;
	}
	int i = 0;
	for (; i < input.size() && !stack2.empty(); ++i)
	{
		input[i] = stack2.top();
		stack2.pop();
	}
	input[i++] = '\0';
	return input.substr(0, i);
}

int main()
{
	cout << removePairs("assassin") << endl;
	cout << removePairs("an assassin sins") << endl;
	cout << removePairs("pacific ocean") << endl;

	return 0;

}