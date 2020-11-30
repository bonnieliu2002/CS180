#include <iostream>
#include <unordered_map>
using namespace std;

// memoization
int fib1(int n) {
	unordered_map<int, int> dp;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

void fill(vector<int> &arr, const int val, int &toReplace) {
	arr[toReplace] = val;
	toReplace = !toReplace;
}

// Bottom-up approach with constance space
int fib2(int n) {
	vector<int> arr(2, 0);
	int toReplace = 0; // which index should I replace next? (must be 0 or 1)
	for (int i = 1; i <= n; i++) {
		if (i <= 2)
			fill(arr, 1, toReplace);
		else
			fill(arr, arr[0] + arr[1], toReplace);
	}
	return arr[!toReplace];
}

int main() {
	cout << fib1(0) << " " << fib2(0) << endl;
	cout << fib1(1) << " " << fib2(1) << endl;
	cout << fib1(2) << " " << fib2(2) << endl;
	cout << fib1(3) << " " << fib2(3) << endl;
	cout << fib1(4) << " " << fib2(4) << endl;
	cout << fib1(5) << " " << fib2(5) << endl;
	cout << fib1(6) << " " << fib2(6) << endl;
	cout << fib1(7) << " " << fib2(7) << endl;
	cout << fib1(25) << " " << fib2(25) << endl;
}