#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/*

Naive solution :

	for each i consider it to be the element which divides the array in
	two parts and solve it like separate question of Buysellstocks-1

*/


int max_stocks_profit(vector<int>& prices, int n) {

	int max_profit = -1;


	for (int i = 0; i < n; ++i)
	{

		// calculate profits of both partition and store the
		// profit in curr_profit


		// split to 0 to i

		int curr_profit1 = -1;
		int min_Price = prices[0];

		for (int j = 1; j < i; ++j)
		{
			if (prices[j] < min_Price) min_Price = prices[j];

			curr_profit1 = max(curr_profit1, prices[j] - min_Price);

		}



		// split to i+1 to n-1

		int curr_profit2 = -1;
		min_Price = prices[i];

		for (int j = i + 1; j < n; ++j)
		{
			if (prices[j] < min_Price) min_Price = prices[j];

			curr_profit2 = max(curr_profit2, prices[j] - min_Price);

		}

		max_profit = max(max_profit, curr_profit1 + curr_profit2);
	}

	return max_profit;
}


/*

	now we can have atmost two transactions in a day
	buy/sell or both

	now we do some precomputations to get the value

	1. we traverse the profit array and store max-profit from i to n-1
	   in profit[i], for that max_price is required which we calculate
	   in reverse fashion simultaneously calcualte profit

*/




int max_stocks_profit_better(vector<int>& prices, int n) {

	vector<int> profit(n);

	int max_price = prices[n - 1];
	int max_profit = 0;

	for (int i = n - 2; i >= 0; --i)
	{

		if (prices[i] > max_price) max_price = prices[i];

		// just taking profit from i+1 to n range
		// or buying at i and selling at max_price point/index
		profit[i] = max(profit[i + 1], max_price - prices[i]);

	}

	int min_price = prices[0];

	for (int i = 1; i < n; ++i)
	{
		// min_price is minimum price in price[0..i]
		if (prices[i] < min_price) {
			min_price = prices[i];
		}

		// Maximum profit is maximum of:
		// a) previous maximum, i.e., profit[i-1]
		// b) (Buy, Sell) at (min_price, price[i]) and add
		//    profit of other trans. stored in profit[i]
		profit[i] = max(profit[i - 1], profit[i] + (prices[i] - min_price));

		/*
			the profit[i-1] element stores profit of possibly 2 transactions
			where as profit[i] is having profit of one
			transaction from i_th to n_th index at this point

			after that the max is stored in profit[i] itself
			which now contains profits of 2 transactions

		*/
	}

	// the final answer is stored in profit[n-1]
	// which is profit from [0_th to n-1 th index]

	return profit[n - 1];
}


/*

Optimal Solution : Dynamic Programming


*/

int max_stocks_profit_optimal(vector<int>& prices, int n) {

	int first_buy = INT_MIN;
	int first_sell = 0;

	int second_buy = INT_MIN;
	int second_sell = 0;


	for (int i = 0; i < n; ++i)
	{
		first_buy = max(first_buy, -prices[i]); // taken -ve values for convenience


		first_sell = max(first_sell, first_buy + prices[i] );

		// -ve first_buy does subtraction, ie.{ first_sell  + (- actual +ve_first_buy)  }
		// first sell contains the profit

		second_buy = max(second_buy, first_sell - prices[i]);
		// prices[i] in 2nd buy is subtracted from profit from first_sell

		second_sell = max(second_sell, second_buy + prices[i]);
		// second_sell is equal to the current selling value + the remaining profit
		// money in hand during second buy

		// so the total profit is stored in the second_sell variable

	}

	return second_sell;
}


int main() {

	int n;
	cin >> n;

	vector<int> prices(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> prices[i];
	}

	cout << "profit is " << max_stocks_profit(prices, n) << nline;
	cout << "profit is " << max_stocks_profit_better(prices, n) << nline;
	cout << "profit is " << max_stocks_profit_optimal(prices, n) << nline;
	return 0;
}