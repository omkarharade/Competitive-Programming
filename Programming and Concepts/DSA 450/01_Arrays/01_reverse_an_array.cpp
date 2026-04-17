#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void print_array(vector<int> &vec, int n) {

	for (int i = 0; i < n; ++i)
	{
		cout << vec[i] << " ";
	}

	cout << nline;
}

void reverse_array_efficient(vector<int> &vec, int n) {

	int i = 0, j = n - 1;

	while (i < j) {

		swap(vec[i], vec[j]);
		i++;
		j--;
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


	// reverse the array using two pointer
	reverse_array_efficient(vec, n);


	// print the array
	print_array(vec, n);

	return 0;
}