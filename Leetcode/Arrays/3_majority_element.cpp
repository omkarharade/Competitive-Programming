#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {

	sort(nums.begin(), nums.end());
	int currElement = nums[0], n = nums.size();
	int size = 1;

	int overallMax = INT_MIN;
	int maxElement = -1;


	for (int i = 1; i < n; i++) {

		if (nums[i] == currElement) {
			size++;
		}
		else {

			if (overallMax < size) {
				overallMax = size;
				maxElement = currElement;
			}
			currElement = nums[i];
			size = 1;
		}
	}

	if (overallMax < size) {
		overallMax = size;
		maxElement = currElement;
	}

	return maxElement;
}

/*
Boyer-Moore Majority Voting Algorithm

used to find the element having majority of more than half
*/

int majorityElement2(vector<int>& nums) {

	int currElement = nums[0], n = nums.size(), count = 1;

	for (int i = 1; i < n; i++) {
		if (currElement == nums[i]) count++;
		else {

			if (count == 0) {
				count++;
				currElement = nums[i];
			}
			else count--;
		}
	}

	return currElement;
}
int main() {


	return 0;
}