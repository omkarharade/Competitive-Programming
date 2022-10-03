#include <bits/stdc++.h>
using namespace std;


/*

 below code is bruteforce with extra space usage

*/

vector<int> buildArray1(vector<int>& nums) {
	vector<int> ans;

	for (int i = 0; i < nums.size(); i++) {

		ans.push_back(nums[nums[i]]);
	}

	return ans;
}

/*

so simple used this equation nums[i]+=n*(nums[nums[i]]%n)

Space Complexity: O(1)
Time Complexity: O(N).
Here is the code for second approach:
*/


vector<int> buildArray2(vector<int> & nums) {

	int n = nums.size();

	for (int i = 0; i < n; i++) {

		nums[i] += (n * (nums[nums[i]] % n));
	}

	for (int i = 0; i < n; i++) {

		nums[i] = nums[i] / n;
	}

	return nums;
}


int main() {


	return 0;
}