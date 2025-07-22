#include <bits/stdc++.h>
using namespace std;
#define nline "\n";



/*

Expected solution :

	create a 1d array and store all elements of
	matrix in the array and sort itd, now
	re-enter the sorted values back in matrix

	time complexity: O(N^2 * logN^2) = O(N^2 * logN)
	space complexity: O(N^2)

*/


vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {


	vector<int> array(N * N);
	int arrIndx = 0;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			array[arrIndx++] = Mat[i][j];
		}
	}

	sort(array.begin(), array.end());
	arrIndx = 0;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			Mat[i][j] = array[arrIndx++];
		}
	}

	return Mat;
}


int main() {


	return 0;
}