#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

void multiply(vector<int> &arr, int num) {

	int carry = 0;

	for (int i = 0; i < arr.size(); i++) {

		int product = arr[i] * num + carry;
		arr[i] = product  % 10;
		carry = product / 10;
	}

	while (carry != 0) {
		int digit = carry % 10;
		carry /= 10;
		arr.push_back(digit);
	}
}

vector<int> factorial(int N) {
	// code here

	vector<int> ans;

	int temp = N;

	while (temp != 0) {

		int digit = temp % 10;
		temp /= 10;

		ans.push_back(digit);
	}

	for (int i = N - 1; i >= 2; i--) {
		multiply(ans, i);
	}

	int lptr = 0, rptr = ans.size() - 1;

	while (lptr < rptr) {

		swap(ans[lptr++], ans[rptr--]);
	}

	return ans;

}

int main() {

	int n;
	cin >> n;

	vector<int> ans = factorial(n);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	cout << nline;


	return 0;
}