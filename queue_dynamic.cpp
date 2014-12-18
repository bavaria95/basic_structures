/* queue implementation on annular array with static size */

#include <iostream>
#include <stdlib.h>

using namespace std;

// const int MAX_SIZE = 200;		// maximum length of queue + 1

struct Queue {
	int *a;						// array to retain queue
	int head;				   // pointer on head of the queue
	int tail;				  // pointer on tail of the queue
	int size;				 // current size of queue
	int n;
};

void init(Queue &q, int capacity = 50)
{
	q.n = capacity;
	q.size = 0;					// firstly set length of queue on 0
	q.head = 0;				   // set head and tail on zero's element in array
	q.tail = 0;
	q.a = new int[q.n];
	}

bool isEmpty(Queue q)
{
	return (q.size == 0);				// checking emptiness of queue
	}

void extend_Queue(Queue &q)
{
	int *b = new int[2 * q.n];
	for (int i = 0; i <= q.n; i++)
		b[i] = q.a[i];
	delete[] q.a;
	q.n = 2 * q.n;
	q.a = b;
	}

void constrict_Queue(Queue &q, bool f)
{
	int *b = new int[q.n / 2];
	if (f)
	{
		int it = 0;
		for (int i = q.head; i <= q.tail; i++, it++)
			b[it] = q.a[i];
		
		q.tail -= q.head;
		q.head = 0;
		}
	else
	{
		int it = 0;
		for (int i = q.tail; i <= q.head; i++, it++)
			b[it] = q.a[i];

		q.head -= q.tail;
		q.tail = 0;
		}

	delete[] q.a;
	q.n = q.n / 2;
	q.a = b;
	}

void push(Queue &q, int key)					// pushing element in the end of queue
{
	cout << "key : " << key << ". size : " << q.n << ". tail : " << q.tail << ". head : " << q.head << '\n';
	if (q.tail >= q.n - 1)
		extend_Queue(q);
	if ((q.tail == q.head) && (q.size > 0))			// checking collision of pointers
	{
		cout << "ERROR1!\n";
		exit(1);
		}	 

	q.size++;
	q.a[q.tail] = key;

	q.tail = (q.tail + 1) % q.n;
	}

int pop(Queue &q)					// taking element from the begin of queue
{
	cout << "key : " << q.head  << ". size : " << q.n << ". tail : " << q.tail << ". head : " << q.head << '\n';
	// if ((q.head < q.n / 4) && (q.tail < q.n / 4))
	// 	constrict_Queue(q);

	if ((q.head < q.tail) && (q.size < q.n / 4))
		constrict_Queue(q, true);
	else
		if ((q.head > q.tail) && (q.size < q.n / 4))
			constrict_Queue(q, false);

	int tmp = q.a[q.head];
	if ((q.tail == q.head) && (q.size > 0))
	{
		cout << "ERROR2!\n";
		exit(1);
		}	 

	q.size--;
	q.head = (q.head + 1) % q.n;
	return tmp;
	}

int main()
{
	Queue Q;
	init(Q);
	cout << "razmer snachala : " << Q.n << '\n';

	for (int i = 0; i <= 100; i++)
		push(Q, i);

	cout << "razmer posle push-ov : " << Q.n << '\n';

	while (!isEmpty(Q))
		cout << pop(Q) << '\n';
	
	// cout << Q.n << '\n';	
	}