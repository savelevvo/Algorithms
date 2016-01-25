#pragma once
#ifndef _ALGORITHMS_H
#define _ALGORITHMS_H

/*****************************
 * Пузырьковая сортировка [63]
 * O(n^2)
**/
template<typename T>
void swap(T *items, const int &lhs, const int &rhs)
{
	if (lhs != rhs)
	{
		T temp = items[lhs];
		items[lhs] = items[rhs];
		items[rhs] = temp;
	}
}
template<typename T>
void bubble_sort(T *arr, const unsigned &lenght)
{
	bool swapped;
	do
	{
		swapped = false;
		for (unsigned i = 1; i < lenght; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr, i - 1, i);
				swapped = true;
			}
		}
	} while (swapped != false);
}


/********************
* Сортировка вставкой
* O(n^2)
**/
template<typename T>
int FindInsertionIndex(T *items, T value, const unsigned &length)
{
	for (unsigned i = 0; i < length; i++)
		if (items[i] > value)
			return i;
	// throw must be here...
}
template<typename T>
void Insert(T *items, const unsigned &indexInsertAt, const unsigned &indexInsertFrom)
{
	T tmp = items[indexInsertAt];
	items[indexInsertAt] = items[indexInsertFrom];
	for (unsigned current = indexInsertFrom; current > indexInsertAt; current--)
		items[current] = items[current - 1];
	items[indexInsertAt + 1] = tmp;
}
template<typename T>
void insert_sort(T *items, const unsigned &length)
{
	for (unsigned sortedRangeEndIndex = 1; sortedRangeEndIndex < length; sortedRangeEndIndex++)
	{
		if (items[sortedRangeEndIndex] < items[sortedRangeEndIndex - 1])
		{
			int insertIndex = FindInsertionIndex(items, items[sortedRangeEndIndex], length);
			Insert(items, insertIndex, sortedRangeEndIndex);
		}
	}
}


/*******************
* Сортировка выбором
* O(n^2)
**/
template<typename T>
int FindIndexOfSmallestFromIndex(T *items, const int &sortedRangeEnd, const int &length)
{
	T currentSmallest = items[sortedRangeEnd];
	int currentSmallestindex = sortedRangeEnd;
	for (int i = sortedRangeEnd + 1; i < length; i++)
	{
		if (currentSmallest > items[i])
		{
			currentSmallest = items[i];
			currentSmallestindex = i;
		}
	}
	return currentSmallestindex;
}
template<typename T>
void select_sort(T *items, const int &length)
{
	for (int sortedRangeEnd = 0; sortedRangeEnd < length; sortedRangeEnd++)
	{
		int nextIndex = FindIndexOfSmallestFromIndex(items, sortedRangeEnd, length);
		swap(items, sortedRangeEnd, nextIndex);
	}
}


/*******************
* Быстрая сортировка
* O(n^2)
**/
template<typename T>
int partition(T *items, int left, int right, int pivotIndex)
{
	T pivotValue = items[pivotIndex];
	swap(items, pivotIndex, right);
	int storeIndex = left;
	for (int i = left; i < right; i++)
	{
		if (items[i] > pivotValue)
		{
			swap(items, i, storeIndex);
			storeIndex += 1;
		}
	}
	swap(items, storeIndex, right);
	return storeIndex;
}
template<typename T>
void qs(T *items, int left, int right)
{
	if (left < right)
	{
		int pivotIndex = 2;// random number
		int newPivot = partition(items, left, right, pivotIndex);

		qs(items, left, newPivot - 1);
		qs(items, newPivot + 1, right);
	}
}
template<typename T>
void quick_sort(T *items, const int &length)
{
	qs(items, 0, length - 1);
}



#endif // !_ALGORITHMS_H


