#include <bits/stdc++.h>
using namespace std;
#define nline "\n";



// brute force approach is to just sort the array


/*

Expected solution is to use two pointer type of approach

	create three partition using 2 pointers - Dutch national flag type
	time c : O(N)
	space c: O(1)

*/


void threeWayPartition(vector<int>& array, int a, int b)
{
	// code here

	int lo = 0, hi = array.size() - 1, curr = 0;

	while (curr <= hi) {

		if (array[curr] < a) {
			swap(array[curr], array[lo]);
			lo++;
			curr++;
		}
		else if (array[curr] > b) {
			swap(array[curr], array[hi]);
			hi--;
		}
		else {
			curr++;
		}
	}
}



int main() {

	int n, a, b;
	cin >> n >> a >> b;

	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	threeWayPartition(arr, a, b);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}