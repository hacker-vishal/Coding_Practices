#include<iostream>
#include<string>
#include <Math.h>
using namespace std;




class Pol
{
public:
        double distance,angle,xco,yco,t,sum,a;
public:
        Pol()
    {


    }
        Pol( double a,double d):angle(a),distance(d)
        {


                calc(angle,distance);


        }
        void calc(double angle,double distance)
        {


                double ang;
                ang=angle*3.14159/180;
                t=ang;
                sum=ang;


                for(int i=1;i<=4;i++)
                {
                        t=(t*(-1)*t*t)/((2*i)*(2*i+1));
                        sum=sum+t;
            }
                a=sum;


                xco=distance*cos(ang);
                yco=distance*a;
                display(xco,yco);








        }


        void display(double xco,double yco)
        {


                cout<<"X-Coordinate : "<<xco<<"\nY-Coordinate : "<<yco<<"\n";
        }






};




class Rec
{
public:
        double xcor,ycor,dist,ang;
        double m,n,z,q,tan,ang1;
public:
        Rec()
    {


    }
        Rec(double x, double y):xcor(x),ycor(y)
        {


                calc(xcor,ycor);
        }
        void calc(double xcor, double ycor)
        {




                m=xcor*xcor;
                n=ycor*ycor;
                z=m+n;


                dist=sqrt(z);


                q=ycor/xcor;






                ang=atan(q);


                ang1=ang*180.0/3.14159;






                display(ang1,dist);








        }


        void display(double ang1, double dist)
        {
                cout<<"Angle : "<<ang1<<"\nDistance : "<<dist<<"\n";


        }






};


int main()
{


        double angle,distance;
        double xcor,ycor;
        int ch;


        cout<<"1 . Polar to Rectangle \n";
        cout<<"2 . Rectangle to Polar \n";
        cout<<"Enter Your choice :\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
                cout<<"Enter Angle :\n";
                cin>>angle;
                cout<<"Enter Distance :\n";
                cin>>distance;
                Pol p1(angle,distance);
                break;
        }
        case 2:
        {
                cout<<"Enter X :\n";
                cin>>xcor;
                cout<<"Enter Y :\n";
                cin>>ycor;
                Rec r1(xcor,ycor);
                break;
        }
        }




}
