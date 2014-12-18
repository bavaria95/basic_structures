#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
	int val;
	Node *next;
};

struct Queue {
	Node *head;
	Node *tail;
};

void init(Queue &q)
{
	q.head = NULL;
	q.tail = NULL;
	}

bool isEmpty(Queue q)
{
	return (q.head == NULL);
	}

void push(Queue &q, int key)
{
	Node *tmp = new Node;
	tmp -> val = key;
	if (q.tail != NULL)
		q.tail -> next = tmp;
	else
		q.head = tmp;
	q.tail = tmp;
	}

int pop(Queue &q)
{
	if (isEmpty(q))
	{
		cout << "Queue is already empty\n";
		exit(1);
		}

	Node *tmp = q.head;
	
	int w = tmp -> val;
	
	q.head = q.head -> next;
	
	delete tmp;
	
	return w;
	}


int main() 
{
	Queue Q;
	init(Q);

	for (int i = 100; i >= 0; i--)
		push(Q, i);

	while (!isEmpty(Q))
		cout << pop(Q) << '\n';
	
	}