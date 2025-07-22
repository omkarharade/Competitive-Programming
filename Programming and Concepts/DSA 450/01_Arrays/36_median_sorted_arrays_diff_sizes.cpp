#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int median_optimal(vector<int>&a, vector<int>&b, int n) {

	int n1 = a.size(), n2 = b.size();
	int lo = 0, hi = n1;

	while ( lo <= hi ) {

		int cut1 = lo + (hi - lo) / 2;
		int cut2 = (n1 + n2) / 2 - cut1;

		int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
		int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
		int r1 = cut1 == n1 ? INT_MAX : a[cut1];
		int r2 = cut2 == n2 ? INT_MAX : b[cut2];

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

			return (
			           (n1 + n2) / 2 == 0 ?
			           (max(l1, l2) + min(r1, r2)) / 2 // for even number of n1 + n2
			           : min(r1, r2)  				// for odd number of n1 + n2
			       );
		}

	}

}

int main() {


	return 0;
}