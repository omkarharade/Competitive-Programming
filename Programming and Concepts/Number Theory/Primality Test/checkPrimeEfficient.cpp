#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

bool checkPrime(int n){

	if(n == 1) return false;

	for (int i = 2; i*i <= n; ++i)
	{
		if(n % i == 0){
			return false;
		}
	}

	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif


	for (int i = 2; i <= 100; ++i)
	{
		if(checkPrime(i)){
			cout << i  << nline;
		}
	}

	return 0;
}