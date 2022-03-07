#include <bits/stdc++.h>
using namespace std;
#define nline "\n"



int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int k;
	cin >> k;

	cin.ignore();
	string s;
	getline(cin, s);
	cout << k << nline;

	cout << s << nline;

	string cipher = "";
	string decipher = "";

	cout << "cipher text = ";

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ') {
			cipher += ' ';
		}
		else
			cipher += (char)((((s[i] - 'a') + k) % 26) + 'A');
	}

	cout << cipher << nline;

	cout << "deciphered text = ";

	for (int i = 0; i < cipher.length(); ++i)
	{
		if (cipher[i] == ' ') decipher += ' ';
		else
			decipher +=  (char)((((cipher[i] - 'A') - k + 26) % 26 ) + 'a');

	}

	cout << decipher << nline;


	return 0;
}
