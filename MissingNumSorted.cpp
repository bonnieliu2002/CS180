#include <iostream>
#include <vector>
using namespace std;

/**********************************************************************************/
/* An array of n elements contains all but one of the integers from 1 to n+1.     */
/* Give the best algorithm you can for determining which number is missing if the */
/* array is sorted, and analyze its asymptotic worst-case running time.           */
/**********************************************************************************/

// overall approach: binary search
// time complexity: O(log n) where n is number of elements in arr

int findMissing(vector<int> arr) {
	int n = arr.size();
	int left = 0;
	int right = n - 1;
	if (arr[left] != 1)
		return 1;
	if (arr[right] != n + 1)
		return n + 1;
	while (right != left + 1) {
		int mid = (left + right) / 2;
		if (arr[mid] >= ((double) arr[left] + arr[right]) / 2)
			right = mid;
		else
			left = mid;
	}
	return (arr[right] + arr[left]) / 2;
}

int main() {
	// a bunch of testing
	vector<int> arr1 = { 1,2,4 };
	vector<int> arr2 = { 1,3,4 };
	vector<int> arr3 = { 1,2,4,5 };
	vector<int> arr4 = { 1,3,4,5 };
	vector<int> arr5 = { 1,2,3,5 };
	vector<int> arr6 = { 2,3,4 };
	vector<int> arr7 = { 1,2,3 };
	vector<int> arr8 = { 1,3 };
	cout << findMissing(arr1) << endl; // should print 3
	cout << findMissing(arr2) << endl; // should print 2
	cout << findMissing(arr3) << endl; // should print 3
	cout << findMissing(arr4) << endl; // should print 2
	cout << findMissing(arr5) << endl; // should print 4
	cout << findMissing(arr6) << endl; // should print 1
	cout << findMissing(arr7) << endl; // should print 4
	cout << findMissing(arr8) << endl; // should print 2
}