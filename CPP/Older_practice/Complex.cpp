
#include<iostream>

#include<string>

using namespace std;

class CComplex

{

    double _real;

    double _imag;


public:

    CComplex(double r = 0, double i = 0) :_real(r), _imag(i) {


    }


    CComplex  operator+(CComplex par) {



        return CComplex(this->_real + par._real, this->_imag + par._imag);

    }


    CComplex  operator+(int par) {


        return CComplex(this->_real, this->_imag + par);

    }


    friend CComplex operator+(int val, const CComplex& par)

    {

        return CComplex(par._real + val, par._imag);

    }


    friend ostream& operator<<(ostream& os, CComplex& par)//friend operator

    {

        os << par._real << (par._imag >= 0.0 ? "+" : "") << par._imag << "i\n";

        return os;

    }





};



int main()

{

    CComplex c1;

    CComplex c2(3, -4);

    CComplex c3 = c1 + c2;

    CComplex c4 = c1 + 10;//10 to be added to imag

    CComplex c5 = 20 + c1; //20 to be added to real


    cout << c1 << c2 << c3 << c4 << c5;


    return 0;

}



