#include<iostream>
#include"Algorithms.h"

using std::cout;
using std::endl;

/* Сортировка слиянием [54] */

int main()
{
	const unsigned SZ = 6;
	int arr[SZ] = { 5, 3, 0, 1, 22, -1 };
	quick_sort(arr, SZ);

	for (int i = 0; i < SZ; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}