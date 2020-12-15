#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// n: number of dice
// m: number of faces each die has (numbered 1,...,m)
// X: total sum to be achieved
int numWays(const int n, const int m, const int X) {
	vector<int> dp_row(X + 1, 0); // 0, 1, 2, 3, ..., X
	vector<vector<int>> dp(n + 1, dp_row); // 0, 1, 2, ..., n
	for (int i = 1; i <= m; i++) {
		if (i <= X)
			dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= X; j++) {
			if (j > i * m || i > j)
				continue;
			for (int k = 1; k <= m; k++) {
				if (j >= k)
					dp[i][j] += dp[i - 1][j - k];
			}
		}
	}
	return dp[n][X];
}

int main() {
	cout << numWays(3, 6, 8) << endl;
}