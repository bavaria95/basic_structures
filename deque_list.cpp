#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
	int val;
	Node *prev;
	Node *next;
};

struct Deque {
	Node *head;
	Node *tail;
};

void init(Deque &q)
{
	q.head = NULL;
	q.tail = NULL;
	}

bool isEmpty(Deque q)
{
	return (q.head == NULL || q.tail == NULL);
	}

void pushBack(Deque &q, int key)
{

	Node *tmp = new Node;
	tmp -> val = key;
	tmp -> prev = q.tail;
	if (q.tail != NULL)
		q.tail -> next = tmp;
	else
		q.head = tmp;
	q.tail = tmp;
	}

void pushFront(Deque &q, int key) 
{
	Node *tmp = new Node;
	tmp -> val = key;
	tmp -> prev = NULL;

	if (q.head != NULL)
	{
		tmp -> next = q.head;
		q.head -> prev = tmp;
		}
	else
	{
		q.tail = tmp;
		q.head = tmp;
		}

	q.head = tmp;
	}

int popFront(Deque &q)
{
	if (isEmpty(q))
	{
		cout << "Deque is already empty\n";
		exit(1);
		}

	Node *tmp = q.head;
	
	int w = tmp -> val;
	
	q.head = q.head -> next;

	if (q.head != NULL)
		q.head -> prev = NULL;
	
	delete tmp;
	
	return w;
	}

int popBack(Deque &q)
{
	int w;

	if (isEmpty(q)) 
	{
		cout << "Deque is already empty\n";
		exit(1);
		}

	if (q.tail != NULL) 
	{
		Node *tmp = q.tail;

		w = tmp -> val;

		q.tail = q.tail -> prev;

		tmp -> prev = NULL;
		
		if (q.tail != NULL)
			q.tail -> next = NULL;

		delete tmp;
		}

	return w;
	}

int main() 
{
	Deque Q;
	init(Q);

	for (int i = 100; i >= 0; i--)
		pushFront(Q, i);
	while (!isEmpty(Q))
		cout << popBack(Q) << '\n';

	}