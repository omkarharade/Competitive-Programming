#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& piles) {
	multiset<int, greater<int>> mst;

	for (int i = 0; i < piles.size(); i++) {
		mst.insert(piles[i]);
	}

	int mySum = 0;

	while (mst.size() >= 3) {

		int alice = *mst.begin();
		mst.erase(mst.begin());

		mySum += *mst.begin();
		mst.erase(mst.begin());

		int bob = *(prev(mst.end()));

		mst.erase(prev(mst.end()));
	}

	return mySum;
}


// without extra space but sorting

int maxCoins2(vector<int> &piles) {

	sort(piles.begin(), piles.end());
	int ptr1 = 0, ptr2 = 1, ptr3 = piles.size() - 1;

	int sum = 0;

	while (ptr2 < ptr3) {

		sum += piles[ptr2];
		ptr1++, ptr2++, ptr3--;
	}

	return sum;
}

int main() {


	return 0;
}