#include<iostream>
using namespace std;

	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor\n";
		}
		void fun()
		{
			cout << "CA fun\n";
		}
		~CA()
		{
			cout << "CA D-tor\n";
		}
	};

	struct Handle
	{
		Handle(CA *ptr, int count = 0) :count(count), ptr(ptr)
		{
		}
		int count;
		CA *ptr;
	};

	class Wrapper//smart pointer
	{
		Handle *hndl;
	public:
		Wrapper(CA* ptr = NULL) :hndl(new Handle(ptr))
		{
			if (hndl->ptr != NULL)
				hndl->count = 1;
		}
		Wrapper(const Wrapper& par) :hndl(par.hndl)//Shallow Copy
		{
			if (hndl->ptr != NULL)
				hndl->count++;
		}
		CA* operator->()
		{
			return hndl->ptr;
		}
		Wrapper& operator=(Wrapper par)//copy and swap
		{
			std::swap(this->hndl, par.hndl);
			return *this;
		}
		~Wrapper()
		{
			hndl->count--;
			if (hndl->count == 0)
			{
				delete hndl->ptr;
				delete hndl;
			}
		}
	};


	int main()
	{
		Wrapper w1(new CA());
		Wrapper w2(w1);
		Wrapper w3(w2);
		cout << "_____________________________\n";
		Wrapper w11(new CA());
		Wrapper w21(w11);

		cout << "_____________________________\n";
		Wrapper w111(new CA());
		cout << "________________________________\n";
		w111 = w21;
		cout << "________________________________\n";
		return 0;
	}

