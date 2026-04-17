#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


int find_min_element_naive(vector<int> &vec, int n) {
	// sorting the array

	// returning the first element in case of ascending order

	// time  : O(N logN) where N is no. of elements
	// space  : O(1)
}


int find_min_element_better(vector<int> &vec, int n) {

	// traverse the array and store the latest smallest number
	// in the result variable


	int minElement = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		if (vec[i] < minElement) {
			minElement = vec[i];
		}
	}

	return minElement;

	// time  : O(N)
	// space : O(1)
}


int find_min_element_efficient(vector<int> &vec, int low, int high) {


	// if array contains only one element

	if (low == high)
		return vec[low];

	// if array contains two elements

	if (low + 1 == high)
		return (vec[low] <= vec[high] ? vec[low] : vec[high]);


	int mid = (low + (high - low) / 2);

	int leftMin = find_min_element_efficient(vec, low, mid);
	int rightMin = find_min_element_efficient(vec, mid + 1, high);


	return (leftMin <= rightMin ? leftMin : rightMin);

	// divide and conquer (tournament method)
	// time : O(n)
	// aux space : O(log n);
}



int main() {

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	return 0;
}