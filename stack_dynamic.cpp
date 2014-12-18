#include <iostream>
#include <stdlib.h>

using namespace std;

struct Stack {
	int n;
	int current;
	int *a;
};

void init(Stack &s) 
{
	s.n = 10;
	s.current = -1;
	s.a = new int[s.n];
	}

int isEmpty(Stack s)
{
	return (s.current == -1);
	}

bool isFull(Stack s)
{
	return (s.current == s.n - 1);
	}

bool less_then_quater(Stack s)
{
	return (s.current < s.n / 4);
	}
	
void extend_Stack(Stack &s)
{
	int *b = new int[2 * s.n];
	for (int i = 0; i < s.n; i++)
		b[i] = s.a[i];
	delete[] s.a;
	s.n = 2 * s.n;
	s.a = b;
	}

void constrict_Stack(Stack &s)
{
	int *b = new int[s.n / 2];
	for (int i = 0; i <= s.current; i++)
		b[i] = s.a[i];
	delete[] s.a;
	s.n = s.n / 2;
	s.a = b;
	}

void push(Stack &s, int key)
{
	if (isFull(s))
		extend_Stack(s);
	s.current ++;
	s.a[s.current] = key;
	}

int pop(Stack &s)
{
	if (less_then_quater(s))
		constrict_Stack(s);

	if (s.current < 0) 
	{
		cout << "Stack is already empty\n";
		exit(1);
		}

	return s.a[s.current--];
	}


int main() {

	Stack S;
	init(S);
	for (int i = 100; i >= 0; i--)
		push(S, i);

	while (!isEmpty(S))
	{
		cout << pop(S) << '\n';
		}
	}	