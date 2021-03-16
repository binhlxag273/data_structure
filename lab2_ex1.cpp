#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <time.h>

using namespace std;

int find_min_idx(vector<int> arr)
{
	int min_idx = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] < arr[min_idx])
			min_idx = i;
	}
	return min_idx;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
	return;
}

auto selection_sort(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		vector<int> curr_vec(arr.begin() + i, arr.end());
		int idx = find_min_idx(curr_vec) + i;
		swap(arr[i], arr[idx]);
	}
	return arr;
}

auto insertion_sort(vector<int> arr)
{
	int current_value;
	int current_idx;
	for (int i = 0; i < arr.size(); i++)
	{
		current_value = arr[i];
		current_idx = i - 1;
		while (current_idx >= 0 && arr[current_idx] > current_value)
		{
			arr[current_idx + 1] = arr[current_idx];
			current_idx--;
		}
		arr[current_idx + 1] = current_value;
	}
	return arr;
}

auto interchange_sort(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
	return arr;
}

auto bubble_sort(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size() - 1; j++)
		{
			if (arr[j + 1] < arr[j])
				swap(arr[j + 1], arr[j]);
		}
	}
	return arr;
}

auto merge(vector<int> arr, int left, int mid, int right)
{
	vector<int> result;
	int ptr_1 = left, ptr_2 = mid + 1;
	while (ptr_1 <= mid && ptr_2 <= right)
	{
		if (arr[ptr_1] > arr[ptr_2])
		{
			result.emplace_back(arr[ptr_2]);
			ptr_2++;
		}
		else if (arr[ptr_1] <= arr[ptr_2])
		{
			result.emplace_back(arr[ptr_1]);
			ptr_1++;
		}
	}

	while (ptr_1 <= mid)
	{
		result.emplace_back(arr[ptr_1]);
		ptr_1++;
	}
	while (ptr_2 <= mid)
	{
		result.emplace_back(arr[ptr_2]);
		ptr_2++;
	}
	
	for (int i = left; i <= right; i++)
	{
		arr[i] = result[i - left];
	}

	return arr;
}

auto mergeSort(vector<int> &arr, int left, int right) {
	if (left == right)
	{
		return arr;
	}
	else if (left + 1 == right && arr[left] > arr[right])
	{
		swap(arr[left], arr[right]);
		return arr;
	}
	else if (left + 1 == right && arr[left] <= arr[right])
	{
		return arr;
	}

	int mid = (left + right) / 2;
	arr = mergeSort(arr, left, mid);
	arr = mergeSort(arr, mid + 1, right);
	arr = merge(arr, left, mid, right);
	return arr;
}

auto HeapSort(vector<int> arr)
{
	priority_queue<int> pq;
	for (int i = 0; i < arr.size(); i++)
	{
		pq.push(arr[i]);
	}
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		arr[i] = pq.top();
		pq.pop();
	}
	return arr;
}

auto partition(vector<int> &arr, int &left, int &right)
{
	srand(time(NULL));
	int pivot = rand() % (right - left + 1);	// probability trick to choose pivot 
	swap(arr[left], arr[pivot + left]);
	pivot = left;
	bool turn = 0;
	while (left <= right)
	{
		if (turn == 0)
		{
			if (arr[left] < arr[pivot]) {
				swap(arr[pivot], arr[left]);
				pivot++;
				left++;
			}
			else if (arr[left] > arr[pivot])
			{
				turn = !turn;
			}
			else if (arr[left] == arr[pivot])
			{
				left++;
			}
		}
		else {
			if (arr[right] <= arr[pivot])
			{
				swap(arr[right], arr[left]);
				swap(arr[left], arr[pivot]);
				pivot++;
				right--;
				left++;
				turn = !turn;
			}
			else if (arr[right] > arr[pivot])
			{
				right--;
			}
		}
	}
	return pivot;
}

void quicksort(vector<int> &arr, int left, int right)
{
	if (left >= right)
		return;
	int i = left, j = right;
	int pivot = partition(arr, i, j);
	quicksort(arr, left, pivot - 1);
	quicksort(arr, j + 1, right);
	return;
}

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	vector<int> arr(n);
	cout << "Nhap phan tu mang: ";
	for (int i = 0; i < n; i++)
	{
		int key;
		cin >> key;
		arr[i] = key;
	}
	quicksort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;

}
