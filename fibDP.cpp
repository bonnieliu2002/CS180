#include <iostream>
#include <unordered_map>
using namespace std;

int fib(int n) {
	unordered_map<int, int> dp;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main() {
	cout << fib(0) << endl;
	cout << fib(1) << endl;
	cout << fib(2) << endl;
	cout << fib(3) << endl;
	cout << fib(4) << endl;
	cout << fib(5) << endl;
	cout << fib(6) << endl;
	cout << fib(7) << endl;
	cout << fib(25) << endl;
}