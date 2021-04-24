#include<iostream>
#include<conio.h>
#include <iostream>
using namespace std;

namespace as04
{

    struct node
    {
        int data;
        node* next;
    };

    class stack
    {
        node* top;
    public:
        stack()
        {
            top = NULL;
        }
        void push();
        void pop();
        void display();
        ~stack();
    };

    void stack::push()
    {
        node* temp;
        temp = new node;
        cout << "Enter data :";
        cin >> temp->data;
        temp->next = top;
        top = temp;
    }

    void stack::pop()
    {
        if (top != NULL)
        {
            node* temp = top;
            top = top->next;
            cout << temp->data << "deleted";
            delete temp;
        }
        else
            cout << "Stack empty";
    }

    void stack::display()
    {
        node* temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    stack::~stack()
    {
        while (top != NULL)
        {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void main()
    {
        stack st;
        char ch;
        do
        {
            cout << "stack options\n1 for push \n2 for Pop \n3 for Display \n4 for quit";
            cin >> ch;
            switch (ch)
            {
            case '1': st.push(); break;
            case '2': st.pop(); break;
            case '3': st.display(); break;
            }
        } while (ch != '4');
    }
}