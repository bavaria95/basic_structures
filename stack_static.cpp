#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX_SIZE = 1000;

struct Stack {
	int n;
	int a[MAX_SIZE];
};

void init(Stack &s) 
{
	s.n = -1;
	}

void push(Stack &s, int key)
{
	s.n ++;
	s.a[s.n] = key;
	}

int pop(Stack &s)
{
	if (s.n < 0) 
	{
		cout << "Stack is already empty\n";
		exit(1);
		}

	return s.a[s.n--];
	}

int isEmpty(Stack s)
{
	return (s.n == -1);
	}

int main() {

	Stack S;
	init(S);
	push(S, 3);
	push(S, 1);
	push(S, 8);

	while (!isEmpty(S))
		cout << pop(S) << '\n';
	cout << pop(S) << '\n';
	}	