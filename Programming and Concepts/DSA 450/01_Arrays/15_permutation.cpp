#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void nextPermutation(vector<int>& nums) {
	int n = nums.size();
	int swapIndx = n - 1;
	bool ok = 0;

	for (int i = n - 1; i - 1 >= 0; i--) {

		if (nums[i - 1] > nums[i]) {
			// if left number is greater than right one do nothing
			// as greater lexicography can't be achieved

			swapIndx = i - 1;
		}
		else if (nums[i - 1] < nums[n - 1]) {
			swap(nums[i - 1], nums[n - 1]);
			sort(nums.begin() + i, nums.end());
			ok = 1;
			break;
		}
		else if (nums[i - 1] < nums[swapIndx]) {
			swapIndx = i - 1;
			sort(nums.begin() + i, nums.end());

			// check for a number just greater than the number at swapIndx
			// sort the rest rightmost numbers

			for (int j = i; j < n; j++) {
				if (nums[j] > nums[swapIndx]) {
					swap(nums[j], nums[swapIndx]);
					ok = 1;
					break;
				}
			}
			ok = 1;
			break;
		}
	}

	// if no swaps are done that means array is in descending order,
	// if thats the case question demands a ascending order array
	// which is just reverse of given array in this case

	if (!ok) {
		int lptr = 0, rptr = n - 1;
		while (lptr < rptr) {
			swap(nums[lptr++], nums[rptr--]);
		}
	}
}

int main() {


	return 0;
}