#include<iostream>
#include<string>
using namespace std;
/*
Assignment
1. Reverse the string
2. Merge Two Arrays
3. Merge two sorted Arrays(*)
4. Converting Infix to Postfix(***)
5. Evaluate postfix(***)
6. Convert infixed expression to Prefix
7. Evaluate Prefix
8. postfix to infix
9. prefix to infix
*/

//input -> a+b*c+(d^e+f*g+h)-i*j+k^s (****)
//output -> abc*+de^fg*+h++ij*-ks^+
namespace nm51
{
	template<typename T>
	class Stack
	{

		T arr[10];
		int top;
	public:
		Stack() :top(-1)
		{
		}
		bool IsEmpty()
		{
			return top == -1;
		}
		bool IsFull()
		{
			return top == 9;
		}
		void Push(T val)
		{
			arr[++top] = val;
		}
		T Pop()
		{
			return arr[top--];
		}
		T Peek()
		{
			return arr[top];
		}
	};

	int Precedence(char opr)
	{
		switch (opr)
		{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			break;
		}
		return -1;
	}

	class Infix2Postfix
	{
		Stack<char> stk;
		string infixed;
		string postfixed;
	public:
		void SetInfixed(string infixed)
		{
			this->infixed = infixed;
		}
		void Covert()
		{
			postfixed = "";
			char ch;
			int length = infixed.length();
			for (size_t i = 0; i < length; i++)
			{
				ch = infixed[i];
				if (isalpha(ch))
				{
					postfixed += ch;
				}
				else if (ch == ')')
				{
					while (stk.Peek() != '(')
					{
						postfixed += stk.Pop();
					}
					stk.Pop();//to remove '(' from the stack
				}
				else
				{
					if (!(ch == '(' || stk.IsEmpty() || stk.Peek() == '('))
					{
						while (!stk.IsEmpty() && stk.Peek() != '(' && Precedence(ch) <= Precedence(stk.Peek()))
						{
							postfixed += stk.Pop();
						}
					}
					stk.Push(ch);
				}
			}
			while (!stk.IsEmpty())
			{
				postfixed += stk.Pop();
			}
		}

		int Evaluate()
		{
			int length = postfixed.length();
			for (size_t i = 0; i < length; i++)
			{
				char ch = postfixed[i];
				if (isalpha(ch))
				{
					cout << "Enter a value for " << ch << " : ";
					int val = 0;
					cin >> val;
					stk.Push(val);
				}
				else
				{
					int y = stk.Pop();
					int x = stk.Pop();
					switch (ch)
					{
					case '+':
						stk.Push(x + y);
						break;
					case '-':
						stk.Push(x - y);
						break;
					case '*':
						stk.Push(x * y);
						break;
					case '/':
						stk.Push(x / y);
						break;
					case '^':
						stk.Push(pow(x, y));
						break;
					default:
						break;
					}
				}
			}

			return stk.Pop();
		}

		string GetPostfixed()
		{
			return postfixed;
		}
	};


	int main()
	{
		string infixed = "a+b*c+d"; //"a+b*c+(d^e+f*g+h)-i*j+k^s";
		string expected = "abc*+d+"; //"abc*+de^fg*+h++ij*-ks^+";
		Infix2Postfix inf2pst;
		inf2pst.SetInfixed(infixed);
		inf2pst.Covert();
		cout << "postfixed : " << inf2pst.GetPostfixed() << endl;
		cout << "expected  : " << expected << endl;

		cout << inf2pst.Evaluate() << endl;
		return 0;
	}

	
}