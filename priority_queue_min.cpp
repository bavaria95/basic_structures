#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int parent(int i)
{
	return (i - 1)/2;
	}

int left(int i)
{
	return (2 * i) + 1;
	}

int right(int i)
{
	return 2 * (i + 1);
	}

int minimum(int A[], int n)
{
	return A[0];
	}

bool isEmpty(int A[], int n)
{
	return n == 0;
	}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
	}

void heapify(int A[], int i, int n)
{
	int smallest = i;
	int l = left(i);
	int r = right(i);
	
	if (l < n && A[l] < A[smallest])
		smallest = l;
	if (r < n && A[r] < A[smallest])
		smallest = r;

	if (smallest != i)
	{
		swap(A[i], A[smallest]);
		heapify(A, smallest, n);
		}
	}

void build_heap(int A[], int n)
{
	for (int i = parent(n - 1); i >= 0; i--)
		heapify(A, i, n);
	}

int extract_min(int A[], int &n)
{
	if (n < 1)
		return -1;
	int min = A[0];
	A[0] = A[--n];
	heapify(A, 0, n);
	return min;
	}

void decrease_key(int A[], int i, int key, int n)
{
	A[i] = key;
	while ((i >= 1) && (A[i] < A[parent(i)]))
	{
		swap(A[i], A[parent(i)]);
		i = parent(i);
		}
	}

void insert_key(int A[], int key, int &n)
{
	n++;
	A[n - 1] = 100;
	decrease_key(A, n - 1, key, n);
	}

int main()
{
	int n = 100;
	int *A = new int[n];
	
	n = 10;
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 10;
		cout << A[i] << " ";
		}
	cout << '\n';

	build_heap(A, n);

	for (int i = 0; i < n; i++)
		cout << A[i] << ' ';
	cout << '\n';

	cout << n << '\n';
	// decrease_key(A, 5, 4, n);
	insert_key(A, 10, n);
	cout << n << '\n';
	cout << "IS? : " << isEmpty(A, n) << "\n";
	while (n > 0)
		cout << extract_min(A, n) << " ";
	cout << '\n';
	cout << "IS? : " << isEmpty(A, n) << "\n";
	}
