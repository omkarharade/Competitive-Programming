#include <bits/stdc++.h>
using namespace std;


// prefix sum implementation


int findMiddleIndex(vector<int>& nums) {

	int n = nums.size();
	int middleIndx = -1;

	for (int i = 1; i < n; i++) {

		nums[i] += nums[i - 1];
	}

	if (nums[n - 1] - nums[0] == 0) {
		return 0;
	}

	for (int i = 1; i < n; i++) {

		if (nums[i - 1] == (nums[n - 1] - nums[i])) {
			middleIndx = i;
			break;
		}
	}

	return middleIndx;
}


// without using prefix sum, just using
// leftsum rightsum checks


int findMiddleIndex2(vector<int>& nums) {

	int rightSum = 0;
	int leftSum = 0;
	int middleIndx = -1;

	int n = nums.size();

	for (int i = 0; i < n; ++i)
	{
		rightSum += nums[i];
	}

	for (int i = 0; i < n; ++i)
	{
		if (leftSum == rightSum - nums[i]) {
			middleIndx = i;
			break;
		}

		leftSum += nums[i];
		rightSum -= nums[i];
	}
}

int main() {

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	cout << findMiddleIndex2(vec) << "\n";
	cout << findMiddleIndex(vec) << "\n";

	return 0;
}