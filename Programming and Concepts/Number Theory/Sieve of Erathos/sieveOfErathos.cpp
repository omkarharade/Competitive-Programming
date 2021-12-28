#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


void sieve(int n){

	if(n <= 1) return;

	bool isPrime[n+1];

	fill(isPrime, isPrime + n+1, true);

	for (int i = 2; i*i <= n; ++i)
	{
		if(isPrime[i]){
			for (int j = i*i; j <= n; j+=i)
			{
				isPrime[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		if(isPrime[i]){
			cout << i << " ";
		}
	}


}



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif

	sieve(100);

	return 0;
}