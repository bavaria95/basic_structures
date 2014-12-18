#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
	int val;
	Node *next;
};

struct Stack {
	Node *top;
};

void init(Stack &s)
{
	s.top = NULL;
	}

bool isEmpty(Stack s)
{
	return (s.top == NULL);
	}

void push(Stack &s, int key)
{
	Node *tmp = new Node;
	tmp -> val = key;
	tmp -> next = s.top;
	s.top = tmp;
	}

int pop(Stack &s)
{
	if (isEmpty(s))
	{
		cout << "Stack is already empty\n";
		exit(1);
		}

	Node *tmp = s.top;
	
	int w = tmp -> val;
	
	s.top = s.top -> next;
	
	delete tmp;
	
	return w;
	}


int main() 
{
	Stack S;
	init(S);

	for (int i = 100; i >= 0; i--)
		push(S, i);

	while (!isEmpty(S))
		cout << pop(S) << '\n';

	}