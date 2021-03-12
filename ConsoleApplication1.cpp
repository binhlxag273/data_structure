// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int binarySearch(vector<int> arr, int left, int right, int value)
{
	if (left > right)
		return -1;
	int mid = (left + right) / 2;

	if (arr[mid] == value) {
		return mid;
	}
	else if (arr[mid] < value) {
		return binarySearch(arr, mid + 1, right, value);
	}
	else if (arr[mid] > value) {
		return binarySearch(arr, left, mid + 1, value);
	}
}

int linearSearch(vector<int> arr, int key)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == key)
			return i;
	}
	return -1;
}

int find_max_idx(vector<int> arr)
{
	int int_max = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		int_max = max(int_max, arr[i]);
	}
	return int_max;
}

int find_min_idx(vector<int> arr)
{
	int min_idx = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		min_idx = min(arr[min_idx], arr[i]);
	}
	return min_idx;
}

int find_min_value(vector<int> arr)
{
	int idx = find_min_idx(arr);
	return arr[idx];
}

int find_max_value(vector<int> arr)
{
	int idx = find_max_idx(arr);
	return arr[idx];
}

bool is_prime(int value)
{
	if (value == 1)
		return false;
	else if (value == 2 || value == 3)
		return true;
	for (int i = 2; i < value / 2 + 1; i++)
	{
		if (value % i == 0)
			return false;
	}
	return true;
}

vector<int> find_all_prime(vector<int> arr)
{
	vector<int> result;
	for (int i = 0; i < arr.size(); i++)
	{
		if (is_prime(arr[i]))
			result.push_back(arr[i]);
	}
	return result;
}

bool is_square_number(int value)
{
	int sqrt_num = sqrt(value);
	if (sqrt_num * sqrt_num == value)
		return 1;
	return 0;
}

int find_square_number(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (is_square_number(arr[i]))
			return i;
	}
	return -1;
}

vector<vector<int>> find_longest_sub_arr(vector<int> arr)
{
	vector<vector<int>> omega;
	vector<int> current_arr;
	for (int i = 0; i < arr.size(); i++)
	{
		if (current_arr.size() == 0 || current_arr[current_arr.size() - 1] <= arr[i])
			current_arr.push_back(arr[i]);
		else {
			omega.push_back(current_arr);
			current_arr.clear();
			current_arr.push_back(arr[i]);
		}
	}
	omega.push_back(current_arr);
	int max_size = omega[0].size();
	vector<int> idxs;
	idxs.push_back(0);
	vector<vector<int>> final_result;
	if (omega.size() > 1)
	{
		for (int i = 1; i < omega.size(); i++)
		{
			if (max_size < omega[i].size()) {
				max_size = omega[i].size();
				idxs.clear();
				idxs.push_back(i);
			}
			else if(max_size == omega[i].size()){
				idxs.push_back(i);
			}
		}
		for (int i = 0; i < idxs.size(); i++)
		{
			final_result.push_back(omega[idxs[i]]);
		}
	}
	return final_result;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
	return;
}

vector<int> insertion_sort(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		vector<int> curr_vec(arr.begin() + i, arr.end());
		int idx = find_min_idx(curr_vec) + i;
		swap(arr[i], arr[idx]);
	}
	return arr;
}

vector<int> selection_sort(vector<int> arr)
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
		arr[current_idx] = current_value;
	}
	return arr;
}

vector<int> interchange_sort(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] < arr[j])
				swap(arr[i], arr[j]);
		}
	}
	return arr;
}

vector<int> bubble_sort(vector<int> arr)
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

int main()
{
	int n, key;
	cout << "Nhap vao kich thuoc mang: ";
	cin >> n;
	vector<int> arr(n);
	cout << "Nhap cac phan tu cua mang: ";
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		arr[i] = value;
	}
	cout << "nhap vao gia tri can tim: ";
	cin >> key;
	int idx = binarySearch(arr, 0, arr.size() - 1, key);
	if (idx == -1)
		cout << "don't exist! ";
	else cout << "tim thay " << key << " o vi tri thu " << idx;
	
	return 0;
}
