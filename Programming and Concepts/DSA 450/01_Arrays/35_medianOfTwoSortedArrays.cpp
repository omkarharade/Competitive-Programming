#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/*
 	basic code to find median in general
 	time complexity : O(n * logn)
 	space complexity : O(1)

 */


int find_median(vector<int> v)
{
	int n = v.size();
	if (n == 1) return v[0];
	int lo = 0, hi = n - 1;

	sort(v.begin(), v.end());

	if (n % 2 == 0) {
		return (v[n / 2] + v[(n / 2) - 1]) / 2;

	}
	else {
		return v[(n - 1) / 2];

	}

	return -1;
}

// we count the median while traversing the array itself

int median_naive(vector<int>&a, vector<int>& b, int n) {

	int median1 = -1, median2 = -1;
	int ptr1 = 0, ptr2 = 0;


	// the process continues for n+1 times , 1 round for each element selection

	for (int i = 0; i <= n; ++i)
	{

		/*
			to handle case where all elements from array a is smaller than first(smallest)
			element from array b
		*/

		if (ptr1 == n) {

			median1 = median2;
			median2 = b[0];  // the smallest element from b array becomes the second median
			break;
		}

		// similairly

		if (ptr2 == n) {

			median1 = median2;
			median2 = a[0];
			break;
		}


		// if element in a[ptr1] is less or equal to b[ptr2] update the median with new ones
		// the smaller median from before is removed and updated with new one

		if (a[ptr1] <= b[ptr2]) {
			median1 = median2;
			median2 = a[ptr1++];
		}

		// similarly

		else {
			median1 = median2;
			median2 = b[ptr2++];
		}
	}

	return (median1 + median2) / 2;

}



/*

Better approach:

	we traverse the first array from backwards and second array from front
	doing so we will swap the greater elements in array a
	than the smallest elements in array b

	in this way all possible big elements from array a goes to b array which
	partition the elements rightfully to their expected array group

	lastly sort both the array and get a[n-1] and b[0] as 2 medians
*/
int median_better(vector<int>&a, vector<int>&b, int n) {

	int ptr1 = n - 1, ptr2 = 0;


	while (ptr2 < n and ptr1 >= 0 and a[ptr1] > b[ptr2])
		swap(a[ptr1--], b[ptr2++]);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	return (a[n - 1] + b[0]) / 2;
}

/*
Optimal : Use of binary search

*/

int median_optimal(vector<int>&a, vector<int>&b, int n) {

	int lo = 0, hi = n;

	while ( lo <= hi ) {

		int cut1 = lo + (hi - lo) / 2;
		int cut2 = n - cut1;

		int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
		int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
		int r1 = cut1 == n ? INT_MAX : a[cut1];
		int r2 = cut2 == n ? INT_MAX : b[cut2];

		// check if l1 > r2

		if (l1 > r2) {

			// expected cut1 is to the left of array a
			hi = cut1 - 1;
		}
		else if (l2 > r1) {

			// expected cut2 is to the left of array b
			// which means simultaneous cut1 to right of array a

			lo = cut1 + 1;
		}
		else {

			// ideal condition for partition is met so return the median
			return (max(l1, l2) + min(r1, r2)) / 2;
		}

	}

}



int main() {


	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	cout <<  "median of two sorted array is " << median_naive(a, b, n) << nline;
	// cout <<  "median of two sorted array is " << median_better(a, b, n) << nline;
	cout <<  "median of two sorted array is " << median_optimal(a, b, n) << nline;

	return 0;
}