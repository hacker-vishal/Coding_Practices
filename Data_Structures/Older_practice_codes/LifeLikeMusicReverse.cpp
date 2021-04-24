#include<iostream>
#include<string>
using namespace std;
namespace nm15
{
class Stack
{
	char arr[100];
	const int max;
	int top;

public:
	Stack(int max, int top) :max(max), top(-1)
	{
	}


	void push(char val)
	{
		arr[++top] = val;
	}

	char pop()
	{
		if (IsEmpty())
		{
			cout << "stack is empty";
		}

		return arr[top--];
	}
	bool IsEmpty()
	{
		return top == -1;
	}




};




int main()
{


	//char str1[100] = "Life Like Music";
	string inputstr;
	cout << "Enter String : ";
	getline(cin, inputstr);
	int max = inputstr.length();
	cout << "\n=====_____=====" << max;
	char* str1 = const_cast<char*>(inputstr.c_str());


	Stack stk(max, -1);
	char temp[100];

	char val;

	for (int i = 0; str1[i] != '\0'; i++)
	{
		stk.push(str1[i]);
	}


	cout << "-------Output String Is-------\n";

	int i = 0;
	while (!stk.IsEmpty())
	{
		val = stk.pop();
		temp[i++] = val;
	}

	i = 0;
	while (i < max)
	{
		//cout << "\n*******8" << max;
		while (temp[i] != ' ')
		{
			stk.push(temp[i++]);
			if (i == max)
				break;

		}
		while (!stk.IsEmpty())
		{
			val = stk.pop();

			cout << val;

		}
		cout << " ";
		i++;
		//cout << "\n==========" << i;



	}





	return 0;
}
}