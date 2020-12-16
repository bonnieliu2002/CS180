/********************************************************************************************
* PROBLEM: Given an n x n matrix where all numbers are distinct, design an efficient	    *
* algorithm that finds the maximum length path (starting from any cell) such that all cells *
* along the path are in increasing order with a difference of 1.							*
********************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLongestPath(vector<vector<int>>& dp, int i, int j, const vector<vector<int>>& mat) {
	int n = mat.size();
	if (i < 0 || j < 0 || i >= n || j >= n)
		return 0;
	if (dp[i][j] != -1) // already calculated before
		return dp[i][j];
	int len = 1; // len includes current element
	if (i - 1 >= 0 && mat[i][j] + 1 == mat[i - 1][j])
		len = max(len, 1 + findLongestPath(dp, i - 1, j, mat));
	if (i + 1 < n && mat[i][j] + 1 == mat[i + 1][j])
		len = max(len, 1 + findLongestPath(dp, i + 1, j, mat));
	if (j - 1 >= 0 && mat[i][j] + 1 == mat[i][j - 1])
		len = max(len, 1 + findLongestPath(dp, i, j - 1, mat));
	if (j + 1 < n && mat[i][j] + 1 == mat[i][j + 1])
		len = max(len, 1 + findLongestPath(dp, i, j + 1, mat));
	dp[i][j] = len;
	return len;
}

int maxLengthPath(const vector<vector<int>>& mat) {
	int n = mat.size();
	vector<vector<int>> dp(n, vector<int>(n, -1));
	int maxLen = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == -1) {
				findLongestPath(dp, i, j, mat);
			}
			maxLen = max(maxLen, dp[i][j]);
		}
	}
	return maxLen;
}

int main() {
	vector<int> row1 = { 1, 2, 9 };
	vector<int> row2 = { 5, 3, 8 };
	vector<int> row3 = { 4, 6, 7 };
	vector<vector<int>> mat;
	mat.push_back(row1);
	mat.push_back(row2);
	mat.push_back(row3);
	cout << maxLengthPath(mat) << endl;
}