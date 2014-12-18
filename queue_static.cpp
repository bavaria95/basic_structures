/* queue implementation on annular array with static size */

#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX_SIZE = 200;		// maximum length of queue + 1

struct Queue {
	int a[MAX_SIZE];			// array to retain queue
	int head;				   // pointer on head of the queue
	int tail;				  // pointer on tail of the queue
	int size;				 // current size of queue
};

void init(Queue &q)
{
	q.size = 0;					// firstly set length of queue on 0
	q.head = 0;				   // set head and tail on zero's element in array
	q.tail = 0;
	}

bool isEmpty(Queue q)
{
	return (q.size == 0);				// checking emptiness of queue
	}

void push(Queue &q, int key)					// pushing element in the end of queue
{
	if ((q.tail == q.head) && (q.size > 0))			// checking collision of pointers
	{
		cout << "ERROR1!\n";
		exit(1);
		}	 

	q.size++;
	q.a[q.tail] = key;

	q.tail = (q.tail + 1) % MAX_SIZE;
	}

int pop(Queue &q)					// taking element from the begin of queue
{
	int tmp = q.a[q.head];
	if ((q.tail == q.head) && (q.size > 0))
	{
		cout << "ERROR2!\n";
		exit(1);
		}	 

	q.size--;
	q.head = (q.head + 1) % MAX_SIZE;
	return tmp;
	}

int main()
{
	Queue Q;
	init(Q);

	for (int i = 0; i <= 20; i++)
		push(Q, i);

	while (!isEmpty(Q))
		cout << pop(Q) << '\n';

	}