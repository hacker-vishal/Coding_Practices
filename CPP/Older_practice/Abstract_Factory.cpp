#include<iostream>
#include<string>
using namespace std;
//abstract factory
class IWindow
{
public:
	virtual void CreateWindow()=0;
	virtual void ShowWindow()=0;
};

class IToolbar
{
public:
	virtual void CreateToolbar()=0;
	virtual void AttachToolbar()=0;
};
class IMenubar
{
public:
	virtual void CreateMenubar()=0;
	virtual void AttachMenubar()=0;
};

class IFactory
{
public:
	virtual IWindow* BuildWindow()=0;
	virtual IToolbar* BuildToolbar()=0;
	virtual IMenubar* BuildMenubar()=0;
};

class MSWindow:public IWindow
{
public:
	void CreateWindow()
	{
		cout<<"MSWindow Created \n";
	}
	void ShowWindow()
	{
		cout<<"MSWindow Shown \n";
	}
};

class MSToolbar:public IToolbar
{
public:
	void CreateToolbar()
	{
		cout<<"MSToolbar Created \n";
	}
	void AttachToolbar()
	{
		cout<<"MSToolbar Attached \n";
	}
};

class MSMenubar:public IMenubar
{
public:
	void CreateMenubar()
	{
		cout<<"MSMenubar Created \n";
	}
	void AttachMenubar()
	{
		cout<<"MSMenubar Attached \n";
	}
};


class MSFactory:public IFactory
{
public:
	IWindow* BuildWindow()
	{
		return new MSWindow();
	}
	IToolbar* BuildToolbar()
	{
		return new MSToolbar();
	}
	IMenubar* BuildMenubar()
	{
		return new MSMenubar();
	}
};

class XWindow:public IWindow
{
public:
	void CreateWindow()
	{
		cout<<"XWindow Created \n";
	}
	void ShowWindow()
	{
		cout<<"XWindow Shown \n";
	}
};

class XToolbar:public IToolbar
{
public:
	void CreateToolbar()
	{
		cout<<"XToolbar Created \n";
	}
	void AttachToolbar()
	{
		cout<<"XToolbar Attached \n";
	}
};

class XMenubar:public IMenubar
{
public:
	void CreateMenubar()
	{
		cout<<"XMenubar Created \n";
	}
	void AttachMenubar()
	{
		cout<<"XMenubar Attached \n";
	}
};


class XFactory:public IFactory
{
public:
	IWindow* BuildWindow()
	{
		return new XWindow();
	}
	IToolbar* BuildToolbar()
	{
		return new XToolbar();
	}
	IMenubar* BuildMenubar()
	{
		return new XMenubar();
	}
};

int main()
{
	IFactory *fact=new XFactory();

	//IWindow *win=new XWindow();
	IWindow *win=fact->BuildWindow();

	win->CreateWindow();
	win->ShowWindow();

	//IToolbar *tool=new XToolbar();
	IToolbar *tool=fact->BuildToolbar();
	tool->CreateToolbar();
	tool->AttachToolbar();

	//IMenubar *menu=new XMenubar();
	IMenubar *menu=fact->BuildMenubar();
	menu->CreateMenubar();
	menu->AttachMenubar();

	return 0;
}