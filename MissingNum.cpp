#include <iostream>
#include <vector>
using namespace std;

/**********************************************************************************/
/* An array of n elements contains all but one of the integers from 1 to n+1.     */
/* Give the best algorithm you can for determining which number is missing if the */
/* array is not sorted, and analyze its asymptotic worst-case running time.       */
/**********************************************************************************/

// overall approach: sum up elements in array, and then leverage Gauss's trick to find missing number
// time complexity: O(n) where n is number of elements in arr

int findMissing(vector<int> arr) {
	int n = arr.size();
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
	}
	return (n + 1) * (n + 2) / 2 - sum;
}

int main() {
	// a bunch of testing
	vector<int> arr1 = { 3,2,4 };
	vector<int> arr2 = { 4,6,2,5,1 };
	vector<int> arr3 = { 4,3,2,1 };
	cout << findMissing(arr1) << endl; // should print 1
	cout << findMissing(arr2) << endl; // should print 3
	cout << findMissing(arr3) << endl; // should print 5
}