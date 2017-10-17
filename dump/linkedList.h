// Raul Martinez
// raul.martinez01@utrgv.edu

#include<string>
#include<iostream>

using namespace std;

template <class THING>
class LL
{
private:
	class node 
	{
	public:
		THING data;
		node * next;
		node(THING x)
		{
			data = x;
			next = NULL;
		}
	};
	node * first;
	node * last;

public:
	LL();
	void insert(string x);
	int size();
	void display();
	bool search(string x);
};

LL::LL()
{
	first = NULL;
	//last = NULL;
}


/* Function for create/insert node in Linked list */
void LL::insert(THING x) {
	node *n = new node(x);

	if (first == NULL) {
		n->next = NULL;
		first = n;
		last = n;
	}
	else {
		n->next = NULL;
		last->next = n;
		last = n;
	}
	
}

int LL::size()
{
	int x = 0;
	node * a = first;

	while (a != NULL)
	{
		x++;
		a = a->next;
	}
	return x;
}

void LL::display()
{
	int x = 0;
	node * a = first;

	while (a != NULL)
	{
		x++;
		cout << a->data << endl;
		a = a->next;
	}
}

bool LL::search(THING x)
{
	node * a = first;

	while (a != NULL)
	{
		if (a->data == x)
			return true;

		a = a->next;
	}
	return false;
}
