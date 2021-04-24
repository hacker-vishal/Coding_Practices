#include<iostream>
using namespace std;

namespace as17
{

#define MAX 5
	int top, status;

	//PUSH
	void push(int stack[], int item)
	{
		if (top == (MAX - 1))
			stack = 0;
		else {
			status = 1;
			++top;
			stack[top] = item;
		}
	}

	//POP
	int pop(int stack[])
	{
		int ret;
		if (top == -1)
		{
			ret = 0;
			status = 0;
		}
		else {
			status = 1;
			ret = stack[top];
			--top;
		}
		return ret;
	}

	//DISPLAY
	void display(int stack[])
	{
		int i;
		cout << "\nThe Stack is:";
		if (top == -1)
		{
			cout << "Empty";
		}
		else {
			for (i = top; i >= 0; i--) {
				cout << "\n|---" << stack[i] << "---|\n";
			}
		}
		cout << "\n";
	}

	//MAIN
	int main() {
		int stack[MAX], item;
		int ch;
		top = -1;

		do
		{
			do
			{
				cout << "\nMAIN MENU";
				cout << "\n1.PUSH(insert) in the Stack";
				cout << "\n2.POP(delete) from the Stack";
				cout << "\nEnd the execution";
				cout << "\nEnter your choice:";
				cin >> ch;
				if (ch < 1 || ch>3)
					cout << ("\nInvalid choice please try again");
			} while (ch < 1 || ch>3);

			switch (ch)
			{
			case 1:
				cout << "\nEnter the element to be PUSHED: ";
				cin >> item;
				cout << item;
				push(stack, item);
				if (status) {
					cout << "\nAfter Pushing ";
					display(stack);
					if (top == (MAX - 1))
						cout << "\nStack is Full";
				}
				else
					cout << "\nStack overflow on Push";
				break;

			case 2:
				item = pop(stack);
				if (status) {
					cout << "\nThe Poped item is " << item << " " << "\nAfter Popping ";
					display(stack);
				}
				else
					cout << "\nStack underflow on Pop";
				break;
			default:
				cout << "\nEnd of Execution";
			}
		} while (ch != 3);

		return 0;
	}
}