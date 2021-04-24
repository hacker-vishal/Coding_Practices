#include<iostream>
#include<string>
using namespace std;

namespace nmChnl
{
//n-2-n
class INotify
{
protected:
	string name;
	INotify(string name) :name(name)
	{
	}
public:
	operator string()
	{
		return name;
	}
	virtual void Notify(string from, string msg) = 0;
};



template<typename T>
struct Node
{
	string key;
	T* subscriber;
	Node* next;
	Node(string key,T *client):key(key), subscriber(client),next(NULL)
	{
	}
};


class Channel
{
	Node<INotify>* head;
	Node<INotify>* tail;
public:
	Channel():head(NULL),tail(NULL)
	{
	}
	void Connect(string key, INotify* client)
	{
		Node<INotify>* node=new Node<INotify>(key, client);
		if (head == NULL)
		{
			head = node;
		}
		else
		{
			tail->next = node;
		}
		tail = node;
	}

	void Disconnect(string key)
	{
		
		Node<INotify>* trav = NULL;
		for (trav = head; trav->next->key != key; trav = trav->next);
		Node<INotify>* temp = trav->next;
		trav->next = trav->next->next;
		cout << "Disconnecting " << temp->key << '\n';
		delete temp;

	}
	void List()
	{
		cout << "__________LIST________________\n";
		for (Node<INotify>* trav = head; trav != NULL; trav = trav->next)
		{
			cout << trav->key << endl;
		}
		cout << "__________________________\n";
	}
	void SendMessage(string from, string to, string msg)
	{
		Node<INotify>* trav = head;
		bool flag = false;
		while (flag==false && trav!=NULL)
		{
			if (to == trav->key) {
				flag = true;
				trav->subscriber->Notify(from, msg);
				break;
			}
			trav = trav->next;
		}
	}
};


class Client :public INotify
{
	Channel* channel;
public:
	Client(string name) :INotify(name)
	{
	}
	void Connect(Channel* channel)
	{
		this->channel = channel;
		channel->Connect(name, this);
	}
	void Disconnect()
	{
		this->channel->Disconnect(name);
	}
	void BroadCast(string msg)
	{
		this->channel->SendMessage(name, "", msg);
	}
	void Send(string to, string msg)
	{
		this->channel->SendMessage(name, to, msg);
	}

	void Notify(string from, string msg)
	{
		cout << "[ " << from << " to  "<<name <<" ]===> " << msg << endl;
	}
};


int main()
{
	Channel* sports = new Channel();
	Client yuvi("yuvi");
	Client sachin("sachin");
	Client kaif("kaif");
	Client sehwag("sehwag");
	Client harbhajan("harbhajan");
	yuvi.Connect(sports);
	sachin.Connect(sports);
	kaif.Connect(sports);
	sehwag.Connect(sports);
	harbhajan.Connect(sports);
	
	sports->List();

	//yuvi.Disconnect();
	//kaif.Disconnect();
	harbhajan.Disconnect();

	sports->List();

	yuvi.Send(kaif, "I would have completed with an over to spare");
	sachin.Send(sehwag, "That was a great innings viru");
	return 0;
}
}