#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/*

naive method:
we can do n^2 solution by searching elements from 1st array in 2nd and 3rd array


method 1 :

 delete all duplicate numbers from array then process the arrays


method 2:
	is the below mentioned code:
	step 1: as the array is sorted we keep three pointers one for each array
	and traverse the array, if a number is smaller among three and not common
	delete it and do pointer++;

	step 2: as array is sorted by doing the above process all the pointers will point
	to the common element then add it to ans vector and increase all pointers
	by one;

	Note : there can be repeated common numbers so we keep track to recently added number

 */


vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
	//code here.

	int ptr1 = 0, ptr2 = 0, ptr3 = 0;
	vector<int> ans;

	while (ptr1 < n1 and ptr2 < n2 and  ptr3 < n3) {

		if (A[ptr1] == B[ptr2] and B[ptr2] == C[ptr3]) {

			if (ans.size() == 0) ans.push_back(A[ptr1]);

			else if (ans.size() > 0 and ans.back() != A[ptr1]) {
				ans.push_back(A[ptr1]);
			}

			ptr1++, ptr2++, ptr3++;
		}
		else {

			int minOfThree = min({A[ptr1], B[ptr2], C[ptr3]});

			if (A[ptr1] == minOfThree) {
				ptr1++;
			}
			else if (B[ptr2] == minOfThree) {
				ptr2++;
			}
			else if (C[ptr3] == minOfThree) {
				ptr3++;
			}
		}

		// Time complexity : O(n1 + n2 + n3)
		// Auxilary space complexity : O(1)
	}

	return ans;
}

int main() {

	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	int a[n1], b[n2], c[n3];

	for (int i = 0; i < n1; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n2; ++i)
	{
		cin >> b[i];
	}

	for (int i = 0; i < n3; ++i)
	{
		cin >> c[i];
	}

	vector<int> ans = commonElements(a, b, b, n1, n2, n3);

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}

	cout << nline;


	return 0;
}