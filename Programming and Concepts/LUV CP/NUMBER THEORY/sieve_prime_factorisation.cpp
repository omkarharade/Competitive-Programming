#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);
vector<int>lp(N, 0);
vector<int>hp(N);

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < N; ++i)
	{
		if (isPrime[i]) {

			lp[i] = hp[i] = i;

			for (int j = 2 * i; j < N; j += i)
			{

				if (lp[j] == 0) {
					lp[j] = i;
				}

				hp[j] = i;
				isPrime[j] = false;


			}
		}
	}

	// showing lowest prime and highest prime from 1 to 100

	for (int i = 1; i < 100; ++i)
	{
		cout << lp[i] << " " << hp[i] << nline;
	}


	// showing the prime factors of a number (num)

	int num; cin >> num;

	// vector<int> primeFactors;
	map<int, int> primeFactors;

	while (num > 1) {

		int primeFactor = lp[num];

		while (num % primeFactor == 0) {
			num /= primeFactor;
			// primeFactors.push_back(primeFactor);
			primeFactors[primeFactor]++;
		}
	}

	cout << "prime factors are " << nline;

	// for (auto p : primeFactors) {
	// 	cout << p << " ";
	// }

	for (auto m : primeFactors) {
		cout << m.first << " " << m.second << nline;
	}
	cout << nline;

	return 0;
}