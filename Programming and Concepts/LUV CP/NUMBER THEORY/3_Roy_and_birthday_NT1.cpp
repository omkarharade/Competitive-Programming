#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
const int N = 1e6 + 10;
const int M = 1e9 + 7;
int fact[N];


int binExpoIter(long long a, long long b, long long m) {
	int ans = 1;

	while (b > 0) {

		if (b & 1) {

			ans  = (ans * 1LL * a) % m;
		}

		a = (a * 1LL * a) % m;
		b >>= 1;
	}

	return ans;
}

void solve() {

	string s;
	cin >> s;

	int slen = s.length();
	int cnt_c = 0;
	int cnt_v = 0;
	unordered_map<char, int> ump;

	for (int i = 0; i < slen; ++i)
	{
		if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') cnt_v++;
		else cnt_c++;

		ump[s[i]]++;
	}

	if (cnt_v - cnt_c > 1) cout << -1 << nline;
	else {

		int ans = (fact[cnt_c + 1]);

		ans = (ans * 1LL * binExpoIter((fact[cnt_c - cnt_v + 1] * 1LL * fact[cnt_v]) % M, M - 2, M) % M);
		ans = (((ans * 1LL * fact[cnt_v]) % M) * 1LL * fact[cnt_c]) % M;

		for (auto m : ump) {

			ans = (ans * 1LL * binExpoIter(fact[m.second], M - 2, M)) % M;
		}
		cout << ans << nline;
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	// code here

	fact[0] = 1;

	for (int i = 1; i < N; ++i)
	{
		fact[i] = (i * 1LL * fact[i - 1]) % M;
	}

	int t; cin >> t;

	while (t--) {

		solve();
	}

	return 0;
}