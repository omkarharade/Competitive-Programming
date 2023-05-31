#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/*

Method 1: Brute Force
select a element and traverse through array for getting count
do this for each element

Time Complexity : O(N^2)
Space Complexity : O(1)

Method 2: Efficient 1
sort the array and count the occurrences

Time Complexity : O(NLogN)
Space Complexity : O(1)

Method 3: Efficient 2 -> code available
Use Hash Map and store frequency of the elements

Time Complexity : O(N)
Space Complexity : O(N)


Method 4: Efficient 3 -> code available
as occurrence  > n/k
	k > n / Occur
	k = (n / Occur) + 1
	k - 1 = n / Occur
	or
	k = (n / Occur) + 2
	k - 2 = n / Occur

	so worst case lets take k - 1 elements for storage

Time Complexity : O(N*k)
Space Complexity : O(k)
*/

int countOccurence_efficient3(int arr[], int n, int k) {
	// Your code here

	unordered_map<int, int> unmap;
	int count = 0;

	for (int i = 0; i < n; i++) {
		unmap[arr[i]]++;
	}

	for (auto m : unmap) {

		if (m.second > n / k) count++;
	}

	return count;
}

int countOccurence_efficient4(int arr[], int n, int k) {

	vector<pair<int, int>> frequency(k - 1);

	// code pending
}

int main() {


	return 0;
}