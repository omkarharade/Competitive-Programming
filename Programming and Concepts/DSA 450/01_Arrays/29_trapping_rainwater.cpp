#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/*
naive approach : O(N*N):

	for each i do the following :

		traverse to left and get the max height from left,
		traverse to right and get the max height from right
		the minimum of both is considered to store water and subtract it from height[i]
		for storage of water obv

		time c: O(N*N)
		space c: O(1)
*/


/*

Better approach: O(N):

	use prefix and suffix array to store the max-height for each i:
	water stored for that i = min (leftMax[i], rightMax[i]) - height[i];

	time c: O(N)
	space c: O(N)

*/

int trapping_water_better(vector<int>& height, int n) {

	vector<int> leftMax(n);
	vector<int> rightMax(n);
	int total_water_stored = 0;

	// calculate leftMax array

	for (int i = 0; i < n; ++i)
	{

		if (i == 0) leftMax[i] = height[i];
		else leftMax[i] = max(leftMax[i - 1], height[i]);
	}

	// calculate rightMax array

	for (int i = n - 1; i >= 0; --i)
	{
		if (i == n - 1) rightMax[i] = height[i];
		else rightMax[i] = max(rightMax[i + 1], height[i]);
	}

	// calculate total_water_stored

	for (int i = 0; i < n; ++i)
	{
		total_water_stored += (min(leftMax[i], rightMax[i]) - height[i]);
	}

	return total_water_stored;
}


/*

Optimal approach : 2 Pointer

	use 2-pointers as the leftmax and rightmax can be handled by pointers
	use total 4 pointers left = 0, right = n-1, leftMax = 0, rightMax = 0
	use left and right for traversing and other two for tracking max heights

	check if height[left] <= height[right] (here it is guranteed that right side a greater height is present)

		then check if leftMax >= height[left] then leftMax = height[left]
		else it means leftMax is greater than height[left] and can store water

		total_water_stored = leftMax - height[left]

		|
		|/////|
		|/////|


	else (it is guranteed that in left a greater height is present to focusing on right only)
		similairly check if rightMax >= height[right] then rightMax = height[right]
		else it means rightMax is greater than height[right] and can store water

		total_water_stored = rightMax - height[right]

		      |
		|/////|
		|/////|

*/

int trapping_water_optimal(vector<int>& height, int n) {

	int left = 0, right = n - 1, leftMax = 0, rightMax = 0;
	int total_water_stored = 0;


	while (left <= right) {

		if (height[left] <= height[right]) { // here max of left is the minimum

			if (leftMax <= height[left]) { // no water can be stored as curr height is max
				leftMax = height[left];
			}
			else {

				total_water_stored += (leftMax - height[left]); // water can be stored in this case
			}

			left++;
		}

		else { // max of right is minimum

			if (rightMax <= height[right]) {
				rightMax = height[right];
			}
			else {

				total_water_stored += (rightMax - height[right]);
			}

			right--;
		}

	}

	return total_water_stored;
}

int main() {

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << "amount of water : " << trapping_water_better(arr, n) << nline;
	cout << "amount of water : " << trapping_water_optimal(arr, n) << nline;

	return 0;
}