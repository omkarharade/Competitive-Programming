//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {

    unordered_map<int, int> unmap;

    for (int i = 0; i < n; i++) {
        unmap[a1[i]]++;
    }

    bool ok = 1;
    for (int i = 0; i < m; i++) {

        if (unmap.find(a2[i]) == unmap.end()) {
            ok = 0;
            break;
        }
        else {
            unmap[a2[i]]--;
            if (unmap[a2[i]] == 0) {
                unmap.erase(a2[i]);
            }
        }
    }

    return (ok ? "Yes" : "No");
}