#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/

/*


naive solution :

	for each i_th buying day:
	search for the maximum price for selling the stock
	require 2 loops nested to one another

	time complexity : O(n*n)
	space complexity : O(1)



better solution :

	store the maximum price from i_th index to n-1 in maxProfit[i]
	traversing in the reverse order to calculate maxprofit
	and store it

	then calculate max profit by traversing the maxProfit array and
	current price

	time complexity : O(n)
 	space complexity: O(n)

*/

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<int> maxProfit(n, 0);

	if (n == 1) return 0;

	maxProfit[n - 1] = prices[n - 1];

	for (int i = n - 2; i >= 0; i--) {

		if (maxProfit[i + 1] > prices[i]) {
			maxProfit[i] = maxProfit[i + 1];
		}
		else {
			maxProfit[i] = prices[i];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << maxProfit[i] << " ";
	}
	cout << "\n";

	int profit = INT_MIN;

	for (int i = 0; i + 1 < n; i++) {

		profit = max(max(profit, maxProfit[i + 1] - prices[i]), 0);
	}

	return profit;
}



int main() {


	return 0;
}