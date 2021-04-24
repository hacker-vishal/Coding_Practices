#include<iostream>
#include<string>
using namespace std;
class Rect
{
public:
        virtual void RectDraw()
        {
                cout << "Rect Drawn\n";
        }
        virtual void RectArea()
        {
                cout << "Rect Area\n";
        }
};
        class Circle:public Rect
        {
                Rect *r;
        public:
                virtual void CircleDraw()
                {
                        cout << "Circle Drawn\n";
                }
                virtual void CircleArea()
                {
                        cout << "Circle Area \n";
                }


                operator Rect*()
                {
                        return this->r;
                }
        };


        


        class Shape :public Circle, public Rect
        {
        public:


        };




        int main()
        {
                Shape sp;
                Circle * circle = &sp;
                circle->CircleDraw();
                circle->CircleArea();
                cout << "_____________________________\n";
                Rect *rect = dynamic_cast<Rect*>(circle);
                rect->RectDraw();
                rect->RectArea();
                return 0;
        }
