#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int test;
	cin >> test;
	while (test --) {
		int n;
		cin >> n;
		int  prefixs[n] = {0};
		vector<int> vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec[i];

		}
		prefixs[0] = vec[0];
		for (int i = 1 ; i < n; i++) {
			prefixs[i] = prefixs[i - 1] + vec[i];
		}
		int mins_element = 999;
		if ( n == 0) {
			cout << vec[0];
		}
		else {
			for (int i = 0 ; i < n; i++) {
				for (int j = i ; j < n; j++) {
					int subarray = i > 0 ? prefixs[j] - prefixs[i - 1] : prefixs[j];
					mins_element = min(mins_element , subarray);
				}
			}
		}
		// cout<<"{"<<sum<<"}";

		cout << mins_element << "\n";
	}
	return 0;
}