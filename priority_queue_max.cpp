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

int maximum(int A[], int n)
{
	return A[0];
	}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
	}

void heapify(int A[], int i, int n)
{
	int largest = i;
	int l = left(i);
	int r = right(i);
	
	if (l < n && A[l] > A[largest])
		largest = l;
	if (r < n && A[r] > A[largest])
		largest = r;

	if (largest != i)
	{
		swap(A[i], A[largest]);
		heapify(A, largest, n);
		}
	}

void build_heap(int A[], int n)
{
	for (int i = parent(n - 1); i >= 0; i--)
	{
		heapify(A, i, n);
		}
	}

int extract(int A[], int &n)
{
	if (n < 1)
		return -1;
	int max = A[0];
	A[0] = A[--n];
	heapify(A, 0, n);
	return max;
	}

void increase_key(int A[], int i, int key, int n)
{
	A[i] = key;
	while ((i >= 1) && (A[i] > A[parent(i)]))
	{
		swap(A[i], A[parent(i)]);
		i = parent(i);
		}
	}

void insert_key(int A[], int key, int &n)
{
	n++;
	A[n] = -10e8;
	increase_key(A, n, key, n);
	}

int main()
{
	int n = 10;
	int *A = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 10;
		cout << A[i] << " ";
		}
	cout << '\n';

	build_heap(A, n);

	int i, key;
	cout << n << '\n';
	//cin >> i >> key;
	increase_key(A, 5, 8, n);
	// insert_key(A, 7, n);
	cout << n << '\n';
	n++;
	while (n > 0)
		cout << extract(A, n) << " ";
	cout << '\n';
	}