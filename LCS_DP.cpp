#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string X, Y;

    cout << "Enter first string: ";
    cin >> X;

    cout << "Enter second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    // Create DP table
    vector<vector<int>> dp(m + 1,
                           vector<int>(n + 1, 0));

    // Build DP table
    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    // Display DP table
    cout << "\nDP Table:\n\n";

    cout << "    ";

    for (int j = 0; j < n; j++) {
        cout << Y[j] << " ";
    }

    cout << endl;

    for (int i = 0; i <= m; i++) {

        if (i == 0)
            cout << "  ";
        else
            cout << X[i - 1] << " ";

        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }

    // Reconstruct LCS
    int i = m;
    int j = n;

    string lcs = "";

    while (i > 0 && j > 0) {

        if (X[i - 1] == Y[j - 1]) {

            lcs += X[i - 1];

            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1]) {

            i--;
        }
        else {

            j--;
        }
    }

    // Reverse because LCS was constructed backwards
    reverse(lcs.begin(), lcs.end());

    cout << "\nLongest Common Subsequence: "
         << lcs << endl;

    cout << "LCS Length: "
         << dp[m][n] << endl;

    return 0;
}
